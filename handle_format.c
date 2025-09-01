#include "main.h"

/**
 * handle_format - handles format specifiers
 * @specifier: format specifier
 * @args: va_list of arguments
 *
 * Return: number of characters printed
 */
int handle_format(char specifier, va_list args)
{
	int printed = 0;

	switch (specifier)
	{
	case 'c':
		printed += _putchar(va_arg(args, int));
		break;
	case 's':
		printed += print_string(va_arg(args, char *));
		break;
	case '%':
		printed += _putchar('%');
		break;
	case 'd':
	case 'i':
		printed += print_int(va_arg(args, int));
		break;
	default:
		printed += _putchar('%');
		printed += _putchar(specifier);
		break;
	}

	return (printed);
}
