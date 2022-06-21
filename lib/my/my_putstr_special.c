/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.lemoine
** File description:
** my_putstr_special
*/

void my_put_nbr_base(int nb, char *base);
void my_putchar(char ch);
int my_putstr(const char *str);

void my_putstr_special(const char *str)
{
    while (*str) {
        if (*str < 8 && *str > 0) {
            my_putchar('\\');
            my_putstr("00");
            my_put_nbr_base(*str, "01234567");
        }
        if (*str > 7 && *str < ' ') {
            my_putchar('\\');
            my_putchar('0');
            my_put_nbr_base(*str, "01234567");
        }
        if (*str == 127) {
            my_putchar('\\');
            my_put_nbr_base(*str, "01234567");
        } else {
            my_putchar(*str);
        }
        str++;
    }
}
