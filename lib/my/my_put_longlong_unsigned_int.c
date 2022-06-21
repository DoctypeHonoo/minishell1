/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.lemoine
** File description:
** my_put_longlong_unsigned_int
*/

void my_putchar(char ch);

void check_zer4(long long unsigned int nb)
{
    if (nb > 0) {
        check_zer4(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}

void my_put_longlong_unsigned_int(long long unsigned int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return;
    }
    check_zer4(nb);
}
