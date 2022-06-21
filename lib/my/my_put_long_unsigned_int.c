/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.lemoine
** File description:
** my_put_long_unsigned_int
*/

void my_putchar(char ch);

void check_zer2(long unsigned int nb)
{
    if (nb > 0) {
        check_zer2(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}

void my_put_long_unsigned_int(long unsigned int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return;
    }
    check_zer2(nb);
}
