#include "main.h"

/**
 * _printf - Custom printf function that handles %d and %i
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, printed_chars = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++; // Move past '%'
            if (format[i] == '\0')
                return (-1); // Incomplete specifier at end

            if (format[i] == 'd' || format[i] == 'i')
            {
                int val = va_arg(args, int);
                printed_chars += print_integer(val);
            }
            else if (format[i] == '%')
            {
                write(1, "%", 1);
                printed_chars++;
            }
            else
            {
                // Unknown specifier, print as-is
                write(1, "%", 1);
                write(1, &format[i], 1);
                printed_chars += 2;
            }
            i++; // Move past specifier
        }
        else
        {
            write(1, &format[i], 1);
            printed_chars++;
            i++;
        }
    }

    va_end(args);
    return printed_chars;
}
