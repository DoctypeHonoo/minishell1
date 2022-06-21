/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.lemoine
** File description:
** my_put_nbr_pointer
*/

int my_strlen(const char *str);
void my_putchar(char ch);

void my_put_nbr_pointer(unsigned long long int nb, char *base)
{
    int size = my_strlen(base);
    if (nb / size != 0)
        my_put_nbr_pointer(nb / size, base);
    my_putchar(base[nb % size]);
}
