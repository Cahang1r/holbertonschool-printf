#include <stdarg.h>
#include <unistd.h>

/* Forward declaration */
int parse_format(const char *format, va_list args);

/* Your _printf function */
int _printf(const char *format, ...)
{
    va_list args;
    int count;

    if (!format)
        return -1;

    va_start(args, format);
    count = parse_format(format, args);
    va_end(args);

    return count;
}

/* Your parse_format function */
int parse_format(const char *format, va_list args)
{
    int i = 0, count = 0;

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'd' || format[i] == 'i')
            {
                int num = va_arg(args, int);
                /* Implement printing integer logic here or call a helper */
                /* For example, a print_number function */
                /* count += print_number(num); */
            }
            else if (format[i] == '%')
            {
                count += write(1, "%", 1);
            }
            else
            {
                count += write(1, "%", 1);
                if (format[i])
                    count += write(1, &format[i], 1);
                else
                    i--;
            }
            i++;
        }
        else
        {
            count += write(1, &format[i], 1);
            i++;
        }
    }
    return count;
}
