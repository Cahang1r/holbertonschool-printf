#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 * Return: 1 on success
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * print_string - prints a string to stdout
 * @s: string to print
 * Return: number of characters printed
 */
int print_string(char *s)
{
    int count = 0;

    if (!s)
        s = "(null)";
    while (*s)
    {
        _putchar(*s++);
        count++;
    }
    return count;
}

/**
 * print_int - prints an integer to stdout
 * @n: integer to print
 * Return: number of characters printed
 */
int print_int(int n)
{
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        count += _putchar('-');
        num = -n;
    }
    else
        num = n;

    if (num / 10)
        count += print_int(num / 10);
    count += _putchar((num % 10) + '0');

    return count;
}

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, printed = 0;

    if (!format)
        return -1;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                break;

            switch (format[i])
            {
                case 'c':
                    printed += _putchar(va_arg(args, int));
                    break;
                case 's':
                    printed += print_string(va_arg(args, char *));
                    break;
                case '%':
                    printed += _putchar('%');
                    break;
                case 'd':
                case 'i':
                    printed += print_int(va_arg(args, int));
                    break;
                default:
                    printed += _putchar('%');
                    printed += _putchar(format[i]);
                    break;
            }
        }
        else
        {
            printed += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return printed;
}



#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *s);
int print_int(int n);

#endif /* MAIN_H */




