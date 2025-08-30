#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
//int print_char(va_list args);
//int print_string(va_list args);
int print_percent(void);
int handle_format(const char *format, va_list args, int *i);
int parse_format(const char *format, va_list args);


int print_integer(int n);

int print_char(char c);
int print_string(char *s);
int print_int(int n);


#endif /* MAIN_H */
