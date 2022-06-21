/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** function that copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
