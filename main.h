#ifndef _DOG_H_
#define _DOG_H_
#include <stdarg.h>
int printIdentifiers(char next, va_list arg);
int _putchar(char c);
int _printf(const char *format, ...);
int print_int(va_list arg);
int print_char(va_list arg);
int print_str(va_list arg);
/**
 * struct identifierStruct - this determines the identifer
 * and function used to print the i dentifier
 * @identifier: character argument
 * @printer: function pointer
 */
typedef struct identifierStruct
{
	char *identifier;
	int (*printer)(va_list);
} identifierStruct;
#endif
