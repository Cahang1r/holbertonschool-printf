#include "main.h"

/**
 * print_integer - Prints an integer
 * @n: Integer to print
 * Return: Number of characters printed
 */
int print_integer(int n)
{
    char buf[12];
    int i = 0, count = 0;
    unsigned int num;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = -n;
    }
    else
    {
        num = n;
    }

    do {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    while (i--)
    {
        write(1, &buf[i], 1);
        count++;
    }

    return count;
}
