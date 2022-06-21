/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.lemoine
** File description:
** my_printf_one
*/

#include <stdarg.h>

void my_putchar(char ch);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_put_nbr_base(int nb, char *base);
void my_putstr_special(const char *str);
void my_put_unsigned(unsigned int);
void my_put_nbr_pointer(unsigned long long int nb, char *base);

void my_printf_one3(const char *format, va_list ap)
{
    if (*format == 'X') {
        my_put_nbr_base(va_arg(ap, int), "0123456789ABCDEF");
        return;
    }
    if (*format == 'p') {
        my_putstr("0x");
        my_put_nbr_pointer(va_arg(ap, long unsigned), "0123456789abcdef");
        return;
    }
    if (*format == 'S') {
        my_putstr_special(va_arg(ap, char *));
        return;
    }
}

void my_printf_one2(const char *format, va_list ap)
{
    if (*format == 'b') {
        my_put_nbr_base(va_arg(ap, int), "01");
        return;
    }
    if (*format == 'u') {
        my_put_unsigned(va_arg(ap, unsigned int));
        return;
    }
    if (*format == 'o') {
        my_put_nbr_base(va_arg(ap, int), "01234567");
        return;
    }
    if (*format == 'x') {
        my_put_nbr_base(va_arg(ap, int), "0123456789abcdef");
        return;
    }
    my_printf_one3(format, ap);
}

void my_printf_one(const char *format, va_list ap)
{
    int digit;
    char c;
    char *str;

    if (*format == 's') {
        str = va_arg(ap, char *);
        my_putstr(str);
        return;
    }
    if (*format == 'c') {
        c = va_arg(ap, int);
        my_putchar(c);
        return;
    }
    if (*format == 'd' || *format == 'i') {
        digit = va_arg(ap, int);
        my_put_nbr(digit);
        return;
    }
    my_printf_one2(format, ap);
}
