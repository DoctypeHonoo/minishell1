/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** my_cd
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../../include/my.h"

int get_args_quantity(char **args)
{
    int i = 0;

    while (args[i] != NULL)
        i++;
    return i;
}

void edit_pwd(shell_t *shell)
{
    t_node *node = shell->env_nodes;

    while (my_strcmp(node->key, "OLDPWD") != 0 && node->next)
        node = node->next;
    if (my_strcmp(node->key, "OLDPWD") == 0)
        node->value = my_strdup(get_param(shell->env_nodes, "PWD"));
    node = shell->env_nodes;
    while (my_strcmp(node->key, "PWD") != 0 && node->next)
        node = node->next;
    if (my_strcmp(node->key, "PWD") == 0)
        node->value = my_strdup(getcwd(shell->pwd, sizeof(shell->pwd)));
}

void my_cd_2(shell_t *shell)
{
    if (access(shell->args[1], F_OK) == -1) {
        my_printf("%s: Aucun fichier ou dossier de ce type.\n", shell->args[1]);
        return;
    }
    if (chdir(shell->args[1]) == -1) {
        my_printf("%s: N'est pas un dossier.\n", shell->args[1]);
        return;
    }
    edit_pwd(shell);
}

void my_cd(shell_t *shell)
{
    if (get_args_quantity(shell->args) > 2) {
        my_printf("cd: Too many arguments.\n");
        return;
    }
    if (get_args_quantity(shell->args) == 1 || my_strcmp(shell->args[1], "~") == 0) {
        chdir(get_param(shell->env_nodes, "HOME"));
        return;
    }
    if (my_strcmp(shell->args[1], "-") == 0) {
        chdir(get_param(shell->env_nodes, "OLDPWD"));
        return;
    }
    my_cd_2(shell);
}
