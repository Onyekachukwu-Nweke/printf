#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int print_int(va_list arg);
int print_str(va_list arg);
int print_char(va_list arg);
int _printf(const char *format, ...);

typedef struct identifierStruct
{
	char *identifier;
	int (*printer)(va_list);
} identifierStruct;

#endif
