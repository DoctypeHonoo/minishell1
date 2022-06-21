/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** my_unsetenv
*/

#include "../../include/my.h"

void my_unsetenv_2(shell_t *shell, t_node **cpy, int i)
{
    if (my_strcmp((*cpy)->next->key, shell->args[i]) == 0) {
        if ((*cpy)->next->next)
            (*cpy)->next = (*cpy)->next->next;
        else {
            (*cpy)->next = NULL;
            return;
        }
    }
    (*cpy) = (*cpy)->next;
}

void my_unsetenv(shell_t *shell)
{
    t_node *cpy;

    if (get_args_quantity(shell->args) == 1) {
        my_printf("unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 1; shell->args[i]; i++) {
        cpy = shell->env_nodes;
        while (cpy->next) {
            my_unsetenv_2(shell, &cpy, i);
        }
    }
}
