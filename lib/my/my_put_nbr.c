/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** function that displays the number given as a parameter
*/

void my_putchar(char ch);

void check_zer5(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        check_zer5(nb / -10);
        my_putchar((nb % 10) * -1 + '0');
    }
    if (nb > 0) {
        check_zer5(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}

void my_put_nbr(int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return;
    }
    check_zer5(nb);
}
