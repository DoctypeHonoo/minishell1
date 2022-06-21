/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** get_param.
*/

#include <stdlib.h>
#include "../../include/my.h"

char *get_param(t_node *env, const char *param)
{
    t_node *node = env;

    while (my_strcmp(node->key, param) && node->next)
        node = node->next;
    if (node)
        return node->value;
    return NULL;
}
