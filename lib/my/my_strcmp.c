/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** function  that compares  the  two  strings  s1 and s2
*/

#include "../../include/my.h"

int special_case(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    if (s1[i] == '\0' && s2[j] != '\0')
        return -1;
    if (s1[i] != '\0' && s2[j] == '\0')
        return 1;
    if (s1[i] == '\0' && s2[j] == '\0')
        return 0;
}

int normal_case(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    if (my_strlen(s1) == my_strlen(s2))
        return 0;
    return my_strlen(s1) - my_strlen(s2);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    if (s1[i] == '\0' || s2[j] == '\0')
        return special_case(s1, s2);
    else
        return normal_case(s1, s2);
}
