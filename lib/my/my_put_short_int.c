/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.lemoine
** File description:
** my_put_short_int
*/

void my_putchar(char ch);

void check_zer6(short int nb)
{
    if (nb < 0) {
        my_putchar('-');
        check_zer6(nb / -10);
        my_putchar((nb % 10) * -1 + '0');
    }
    if (nb > 0) {
        check_zer6(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}

void my_put_short_int(short int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return;
    }
    check_zer6(nb);
}
