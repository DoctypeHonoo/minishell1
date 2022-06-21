/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#include <stddef.h>

#ifndef MY_H_
    #define MY_H_

typedef struct s_node {
    char *key;
    char *value;
    struct s_node *next;
} t_node;

typedef struct s_console {
    char *console;
    char **args;
    t_node *env_nodes;
    char *cmd;
    size_t length;
    char pwd[1024];
    int child;
    int status;
} shell_t;

typedef struct array {
    char **array;
    int i;
    int target;
    int index;
    int cpy;
} array_t;

t_node *char_to_node(char **env);
char *get_param(t_node *env, const char *param);
void my_putchar(char ch);
void my_env(t_node *env);
char *my_strdup(char const *src);
void my_cd (shell_t *shell);
int my_strlen(char const *str);
int is_in(const char *str, char ch);
void my_unsetenv(shell_t *shell);
void my_setenv(shell_t *shell);
char *where_is_cmd(char *cmd, t_node *environement);
char **my_links_to_word_array(char const *str);
int get_args_quantity(char **args);
char **my_str_to_word_array(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_printf(const char *format, ...);

#endif /* !MY_H_ */
