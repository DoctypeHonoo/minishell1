/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** my_links_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int check_alpha_2(char ch)
{
    if (ch == ':')
        return 0;
    return 1;
}

int calc_words_2(char const *str)
{
    int i = 0;
    int words = 1;

    while (str[i] != '\0') {
        if (check_alpha_2(str[i]) == 0)
            words++;
        i++;
    }
    return words;
}

int word_size_2(char const *str, int target)
{
    int size = 0;

    while (check_alpha_2(str[target]) == 1 && str[target] != '\0') {
        size++;
        target++;
    }
    return size;
}

char **my_links_to_word_array(char const *str)
{
    int words = calc_words_2(str);
    char **array = malloc(sizeof(char *) * (words + 1));
    int i = 0;
    int index = 0;
    int target = 0;
    int cpy = 0;

    while (str[target] != '\0') {
        int size = word_size_2(str, target);
        array[index] = malloc(sizeof(char) * (size + 1));
        cpy = target;
        while (str[target] != str[cpy + size]) {
            array[index][i] = str[target];
            target++;
            i++;
        }
        array[index][i] = '\0';
        target++;
        index++;
        i = 0;
    }
    array[words] = NULL;
    return array;
}
