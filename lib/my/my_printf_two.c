/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.lemoine
** File description:
** my_printf_two
*/

#include <stdarg.h>

void my_putchar(char ch);
int my_put_short_int(short int nb);
int my_put_short_unsigned_int(short unsigned int nb);
int my_put_long_int(long int nb);
int my_put_long_unsigned_int(long unsigned int nb);
void my_put_long_base(long int nb, char *base);

void my_printf_two2(const char *format, va_list ap)
{
    if (*format == 'l') {
        if (format[1] == 'X') {
            my_put_long_base(va_arg(ap, long unsigned int), "0123456789ABCDEF");
            return;
        }
    }
    if (*format == 'h') {
        if (format[1] == 'i' || format[1] == 'd') {
            my_put_short_int(va_arg(ap, int));
            return;
        }
        if (format[1] == 'u') {
            my_put_short_unsigned_int(va_arg(ap, unsigned int));
            return;
        }
    }
}

void my_printf_two(const char *format, va_list ap)
{
    if (*format == 'l') {
        if (format[1] == 'i' || format[1] == 'd') {
            my_put_long_int(va_arg(ap, long int));
            return;
        }
        if (format[1] == 'u') {
            my_put_long_unsigned_int(va_arg(ap, long unsigned int));
            return;
        }
        if (format[1] == 'o') {
            my_put_long_base(va_arg(ap, long unsigned int), "01234567");
            return;
        }
        if (format[1] == 'x') {
            my_put_long_base(va_arg(ap, long unsigned int), "0123456789abcdef");
            return;
        }
    }
    my_printf_two2(format, ap);
}
