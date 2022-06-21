/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** env_content
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../../include/my.h"

char *where_is_cmd(char *cmd, t_node *env)
{
    char *str = malloc(sizeof(char) * 1000);
    char **links;

    while (my_strcmp(env->key, "PATH") != 0 && env->next)
        env = env->next;
    if (env->next == NULL && my_strcmp(env->key, "PATH") != 0)
        return NULL;
    links = my_links_to_word_array(env->value);
    for (int i = 0; links[i] != NULL; i++) {
        for (int j = 0; j < 1000; j++)
            str[j] = 0;
        my_strcpy(str, links[i]);
        my_strcat(str, "/");
        my_strcat(str, cmd);
        if (access(str, X_OK) == 0)
            return str;
    }
    return NULL;
}
