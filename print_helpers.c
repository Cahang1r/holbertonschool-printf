#include <unistd.h>
#include "main.h"

/**
 * print_char - prints a single character
 * @c: character to print
 *
 * Return: 1 (number of characters printed)
 */
int print_char(char c)
{
    return write(1, &c, 1);
}

/**
 * print_string - prints a string
 * @s: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *s)
{
    int i = 0;

    if (!s)
        s = "(null)";
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return i;
}

/**
 * print_int - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_int(int n)
{
    unsigned int num;
    int count = 0;
    char c;

    if (n < 0)
    {
        count += write(1, "-", 1);
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
        count += print_int(num / 10);

    c = (num % 10) + '0';
    count += write(1, &c, 1);

    return count;
}
