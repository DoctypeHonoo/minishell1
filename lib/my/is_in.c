/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** is_in
*/

int is_in(const char *str, char ch)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch)
            return 1;
    }
    return 0;
}
