/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.lemoine
** File description:
** my_put_unsigned
*/

void my_putchar(char ch);

void check_zer8(unsigned int nb)
{
    if (nb > 0) {
        check_zer8(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}

void my_put_unsigned(unsigned int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return;
    }
    check_zer8(nb);
}
