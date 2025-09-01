#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int print_string(char *s);
int print_int(int n);
int _printf(const char *format, ...);
int handle_format(char specifier, va_list args);

#endif /* MAIN_H */
