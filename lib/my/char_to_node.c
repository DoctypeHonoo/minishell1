/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** char_to_node
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node t_node;
struct s_node {
    char *key;
    char *value;
    t_node *next;
};

void node_push_back(t_node **node, char *key, char *value)
{
    t_node *next_node = malloc(sizeof(t_node));
    t_node *prev_node = malloc(sizeof(t_node));

    next_node->value = value;
    next_node->key = key;
    next_node->next = NULL;
    if (*node == NULL) {
        *node = next_node;
        return;
    }
    prev_node = *node;
    while (prev_node->next != NULL)
        prev_node = prev_node->next;
    prev_node->next = next_node;
}

char *get_key_value(char *env, int key_value)
{
    char *value;
    int i = 0;
    int j = 0;
    if (key_value == 0) {
        while (env[i] != '=') {
            i++;
        }
        value = malloc(sizeof(char) * (i + 1));
        i = 0;
        while (env[i] != '=') {
            value[i] = env[i];
            i++;
        }
    } else {
        while (env[i] != '=') {
            i++;
        }
        i++;
        while (env[i] != '\0') {
            j++;
            i++;
        }
        value = malloc(sizeof(char) * (j + 1));
        i = i - j;
        j = 0;
        while (env[i] != '\0') {
            value[j] = env[i];
            j++;
            i++;
        }
    }
    return value;
}

t_node *char_to_node(char **env)
{
    t_node *env_nodes = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        node_push_back(&env_nodes, get_key_value(env[i], 0), get_key_value(env[i], 1));
    }
    return env_nodes;
}
