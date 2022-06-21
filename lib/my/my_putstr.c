/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** function that displays the characters of a string
*/

int my_putchar(char ch);

int my_putstr(char const *str)
{
    int p = 0;
    while (str[p] != '\0') {
        my_putchar(str[p]);
        p++;
    }
    return (0);
}
