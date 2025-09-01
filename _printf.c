#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed (excluding null byte),
 *         or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printed = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				va_end(args);
				return (-1);
			}
			printed += handle_format(format[i], args);
		}
		else
		{
			printed += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (printed);
}
