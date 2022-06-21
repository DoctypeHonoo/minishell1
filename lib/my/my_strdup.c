/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** duplicates a string in a new area
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len + 1));

    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return dest;
}
