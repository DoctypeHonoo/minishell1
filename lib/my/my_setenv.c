/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** my_setenv
*/

#include <stdlib.h>
#include "../../include/my.h"

int is_alpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 48 && str[i] <= 57) ||
        (str[i] >= 65 && str[i] <= 90) ||
        (str[i] >= 97 && str[i] <= 122))
            continue;
        else
            return 1;
    }
    return 0;
}

int has_alpha(shell_t *shell)
{
    if (is_alpha(shell->args[1]))
            return 1;
    if (get_args_quantity(shell->args) == 3) {
        if (is_alpha(shell->args[2]))
            return 1;
    }
    return 0;
}

void my_setenv(shell_t *shell)
{
    t_node *cpy = shell->env_nodes;
    t_node *new = malloc(sizeof(t_node));

    if (get_args_quantity(shell->args) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return;
    }
    if (get_args_quantity(shell->args) == 1) {
        my_env(shell->env_nodes);
        return;
    }
    if (shell->args[1][0] >= 48 && shell->args[1][0] <= 57) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return;
    }
    if (has_alpha(shell)) {
        my_printf("setenv: Variable name must contain alphanumeric characters.\n");
        return;
    }
    while (cpy->next && my_strcmp(cpy->next->key, shell->args[1]) != 0)
        cpy = cpy->next;
    new->key = shell->args[1];
    if (get_args_quantity(shell->args) == 2)
        new->value = "";
    else
        new->value = shell->args[2];
    cpy->next = new;
}
