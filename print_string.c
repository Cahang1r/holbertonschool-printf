#include "main.h"

/**
 * print_string - prints a string to stdout
 * @s: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *s)
{
	int count = 0;

	if (!s)
		s = "(null)";

	while (*s)
	{
		_putchar(*s);
		s++;
		count++;
	}

	return (count);
}
