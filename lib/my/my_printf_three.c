/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.lemoine
** File description:
** my_printf_three
*/

#include <stdarg.h>

void my_put_longlong_unsigned_int(long long unsigned int nb);
void my_put_longlong_int(long long int nb);
void my_put_longlong_base(long long unsigned int nb, char *base);

void my_printf_three2(const char *format, va_list ap)
{
    if (format[1] == 'X' || format[2] == 'X') {
        my_put_longlong_base(va_arg(ap, long long unsigned int), "0123456789ABCDEF");
        return;
    }
}

void my_printf_three(const char *format, va_list ap)
{
    if (format[1] == 'u' || format[2] == 'u') {
        my_put_longlong_unsigned_int(va_arg(ap, long long unsigned int));
        return;
    }
    int temp = format[1] == 'd' || format[2] == 'd' ? 1 : 0;
    if (format[1] == 'i' || format[2] == 'i' || temp) {
        my_put_longlong_int(va_arg(ap, long long int));
        return;
    }
    if (format[1] == 'o' || format[2] == 'o') {
        my_put_longlong_base(va_arg(ap, long long unsigned int), "01234567");
        return;
    }
    if (format[1] == 'x' || format[2] == 'x') {
        my_put_longlong_base(va_arg(ap, long long unsigned int), "0123456789abcdef");
        return;
    }
    my_printf_three2(format, ap);
}
