#include "main.h"

/**
 * print_char - prints a character
 * @args: va_list containing the character
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @args: va_list containing the string
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}

	return (count);
}

/**
 * print_percent - prints a percent sign
 *
 * Return: number of characters printed
 */
int print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

/**
 * handle_format - handles a format specifier
 * @format: format string
 * @args: argument list
 * @i: pointer to current index in format
 *
 * Return: number of characters printed, or -1 on error
 */
int handle_format(const char *format, va_list args, int *i)
{
	int count = 0;

	(*i)++;

	if (!format[*i])
		return (-1);

	if (format[*i] == 'c')
		count += print_char(args);
	else if (format[*i] == 's')
		count += print_string(args);
	else if (format[*i] == '%')
		count += print_percent();
	else
	{
		write(1, "%", 1);
		write(1, &format[*i], 1);
		count += 2;
	}

	return (count);
}
