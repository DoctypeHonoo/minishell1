/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** my_env
*/

#include <stdlib.h>
#include "../../include/my.h"

void my_env(t_node *env)
{
    while (env) {
        my_printf("%s=%s\n", env->key, env->value);
        env = env->next;
    }
}
