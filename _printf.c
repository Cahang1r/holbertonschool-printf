#include "main.h"

/**
 * parse_format - processes the format string
 * @format: format string
 * @args: argument list
 * Return: number of characters printed
 */
int parse_format(const char *format, va_list args)
{
	int i = 0, count = 0, result;

	while (format[i])
	{
		if (format[i] == '%')
		{
			result = handle_format(format, args, &i);
			if (result == -1)
				return (-1);
			count += result;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	if (!format)
		return (-1);

	va_start(args, format);
	count = parse_format(format, args);
	va_end(args);

	return (count);
}
