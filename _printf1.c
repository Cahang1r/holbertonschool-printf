#include <stdarg.h>
#include <unistd.h>

/* Function to print a single character */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/* Recursive function to print an integer */
int print_number(int n)
{
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        if (n == -2147483648) /* Handle INT_MIN edge case */
        {
            count += write(1, "2147483648", 10);
            return count;
        }
        n = -n;
    }

    if (n / 10)
        count += print_number(n / 10);

    count += _putchar((n % 10) + '0');

    return count;
}

/* Handler for %d and %i */
int handle_di(va_list args)
{
    int num = va_arg(args, int);
    return print_number(num);
}

/* Minimal printf that only supports %d and %i */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format)
        return -1;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'd' || format[i] == 'i')
                count += handle_di(args);
            else if (format[i] == '%') /* To print a literal '%' */
                count += _putchar('%');
            else
            {
                /* If unknown specifier, just print it literally */
                count += _putchar('%');
                if (format[i])
                    count += _putchar(format[i]);
                else
                    i--; /* If end of string, rewind */
            }
            i++;
        }
        else
        {
            count += _putchar(format[i]);
            i++;
        }
    }

    va_end(args);
    return count;
}

/* Test main */
#ifdef TEST_PRINTF
#include <stdio.h>
int main(void)
{
    int len1 = _printf("Hello %d %i %%\n", 123, -456);
    int len2 = printf("Hello %d %i %%\n", 123, -456);

    _printf("Length custom printf: %d\n", len1);
    printf("Length standard printf: %d\n", len2);

    return 0;
}
#endif
