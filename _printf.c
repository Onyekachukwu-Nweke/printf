#include "main.h"
#include <stdio.h>

/**
 * printIdentifiers - functions that selects the identifier
 * @next: character identifier
 * @arg: list of arguments to be processed and printed
 * Return: Function call or 0.
 */

int printIdentifiers(char next, va_list arg)
{
	int funcIndex;

	identifierStruct functs[] = {
		{"c", print_char}, {"s", print_str},
		{"d", print_int}, {"i", print_int},
		{NULL, NULL}
	};

	for (funcIndex = 0; functs[funcIndex].identifier != NULL; funcIndex++)
	{
		if (functs[funcIndex].identifier[0] == next)
		{
			return (functs[funcIndex].printer(arg));
		}
	}

	return (0);
}

/**
 * _printf - main function that prints all specifier
 * @format: argument
 *
 * Return: number of character printed on success or -1 on failure
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int identifierPrinted = 0, charPrinted = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			charPrinted++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			charPrinted++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);
		identifierPrinted = printIdentifiers(format[i + 1], arg);
		if (identifierPrinted == -1 || identifierPrinted != 0)
			i++;
		if (identifierPrinted > 0)
			charPrinted += identifierPrinted;
		if (identifierPrinted == 0)
		{
			_putchar('%');
			charPrinted++;
		}
	}
	va_end(arg);
	return (charPrinted);
}
