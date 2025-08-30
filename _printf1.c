#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to format specifiers
 * @format: format string
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                count += print_char(va_arg(args, int));
            else if (format[i] == 's')
                count += print_string(va_arg(args, char *));
            else if (format[i] == '%')
                count += print_char('%');
            else if (format[i] == 'd' || format[i] == 'i')
                count += print_int(va_arg(args, int));
            else
            {
                /* Print unknown % sequence as is */
                count += print_char('%');
                if (format[i])
                    count += print_char(format[i]);
                else
                    i--;
            }
        }
        else
        {
            count += print_char(format[i]);
        }
        i++;
    }

    va_end(args);
    return (count);
}
