/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int check_alpha(char ch)
{
    if (ch == ' ' || ch == '\t' || ch == '\n')
        return 0;
    return 1;
}

int calc_words(char const *str)
{
    int i = 0;
    int words = 1;

    while (str[i] != '\0') {
        if (check_alpha(str[i]) == 0)
            words++;
        i++;
    }
    return words;
}

int word_size(char const *str, int target)
{
    int size = 0;

    while (!check_alpha(str[target]))
        target++;
    while (check_alpha(str[target]) == 1 && str[target] != '\0') {
        size++;
        target++;
    }
    return size;
}

void edit_var(char const *str, array_t *arr, int size)
{
    while (str[(*arr).target] != str[(*arr).cpy + size]) {
        (*arr).array[(*arr).index][(*arr).i] = str[(*arr).target];
        (*arr).target++;
        (*arr).i++;
    }
    (*arr).array[(*arr).index][(*arr).i] = '\0';
    (*arr).target++;
    (*arr).index++;
    (*arr).i = 0;
}

char **my_str_to_word_array(char const *str)
{
    int words = calc_words(str);
    array_t arr;
    int size;

    arr.array = malloc(sizeof(char *) * (words + 1));
    arr.i = 0;
    arr.index = 0;
    arr.target = 0;
    arr.cpy = 0;
    while (str[arr.target] != '\0') {
        size = word_size(str, arr.target);
        arr.array[arr.index] = malloc(sizeof(char) * (size + 1));
        arr.cpy = arr.target;
        edit_var(str, &arr, size);
    }
    arr.array[words] = NULL;
    return arr.array;
}
