/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "include/my.h"
#include <signal.h>

#define UNUSED() __attribute__((unused))

char **node_to_array(t_node *env)
{
    t_node *cpy = env;
    t_node *cpy2 = env;
    int i = 0;

    while (cpy->next) {
        cpy = cpy->next;
        i++;
    }
    char **env_array = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j < i; j++) {
        env_array[j] = malloc(sizeof(char) * (my_strlen(cpy2->key) + my_strlen(cpy2->value) + 2));
        cpy2 = cpy2->next;
    }
    for (int j = 0; j < i; j++) {
        my_strcat(env_array[j], env->key);
        my_strcat(env_array[j], "=");
        my_strcat(env_array[j], env->value);
        env = env->next;
    }
    return env_array;
}

int exec_binary(shell_t *shell)
{
    int signal;

    shell->cmd = where_is_cmd(shell->args[0], shell->env_nodes);
    shell->child = fork();
    if (shell->child == 0) {
        if (shell->cmd != NULL) {
            execve(shell->cmd, shell->args, node_to_array(shell->env_nodes));
            return 0;
        }
        if (is_in(shell->args[0], '/')) {
            execve(shell->args[0], shell->args, node_to_array(shell->env_nodes));
            return 0;
        } else
            my_printf("%s: Command not found.\n", shell->args[0]);
    } else if (waitpid(shell->child, &shell->status, 0) == 1)
        return 84;
    signal = WTERMSIG(shell->status);
    if (signal == 0)
        return 0;
    if (!strcmp(strsignal(signal), "Floating point exception"))
        my_printf("Floating exception");
    else
        my_printf("%s", strsignal(signal));
    if (WCOREDUMP(shell->status))
        my_printf(" (core dumped)");
    my_printf("\n");
    return 0;
}

int handle_cmds_2(shell_t *shell)
{
    if (my_strcmp(shell->args[0], "unsetenv") == 0) {
        my_unsetenv(shell);
        return 0;
    }
    if (my_strcmp(shell->args[0], "setenv") == 0) {
        my_setenv(shell);
        return 0;
    }
    return exec_binary(shell);
}

int handle_cmds(shell_t *shell)
{
    if (my_strcmp(shell->args[0], "cd") == 0) {
        my_cd(shell);
        return 0;
    }
    if (my_strcmp(shell->args[0], "env") == 0) {
        my_env(shell->env_nodes);
        return 0;
    }
    if (my_strcmp(shell->args[0], "exit") == 0) {
        my_printf("exit\n");
        exit(0);
    }
    return handle_cmds_2(shell);
}

int main(int argc UNUSED(), char **argv UNUSED(), char **env)
{
    shell_t shell = {.console = NULL, .env_nodes = char_to_node(env),
    .length = 0};

    while (42) {
        my_printf("╚> %s 》", getcwd(shell.pwd, sizeof(shell.pwd)));
        if (getline(&shell.console, &shell.length, stdin) == -1)
            return 0;
        shell.console[shell.length - 1] = '\0';
        shell.args = my_str_to_word_array(shell.console);
        for (int i = 0; shell.args[i]; i++) {
            printf("%s\n", shell.args[i]);
        }
        if (handle_cmds(&shell) == 84)
            return 84;
    }
    return 0;
}
