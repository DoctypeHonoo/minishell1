/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-guillaume.lemoine
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>

void my_putchar(char ch);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_printf_one(const char *format, va_list ap);
void my_printf_two(const char *format, va_list ap);
void my_printf_three(const char *format, va_list ap);

void check_multiple_char(const char *format, va_list ap)
{
    if (*format == 'l' || *format == 'h' || *format == 'L') {
        if (format[1] == 'l' || *format == 'L') {
            my_printf_three(format, ap);
        } else {
            my_printf_two(format, ap);
        }
    } else {
        my_printf_one(format, ap);
    }
}

int my_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int counter = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            check_multiple_char(format, ap);
            counter++;
        } else {
            my_putchar(*format);
            counter++;
        }
        format++;
    }
    va_end(ap);
    return counter;
}
