/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** function that counts and returns
** the number of characters found
** in the string passed as parameter
*/

int my_strlen(char const *str)
{
    int p = 0;

    while (str[p] != '\0')
        p++;
    return p;
}
