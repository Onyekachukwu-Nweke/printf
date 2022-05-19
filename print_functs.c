#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * print_char - prints only characters
 * @arg: argument
 *
 * Return: On success 1
 * On error returns -1.
 */

int print_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 * print_str - prints strings
 * @arg: arguments
 * Return: i - number of characters
 */

int print_str(va_list arg)
{
	int i;
	char *s = va_arg(arg, char *);

	if (s == NULL)
		s = "(nil)";
	else if (*s == '\0')
		return (-1);

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
	return (i);
}

/**
 * print_int - prints integers
 * @arg: arugment
 *
 * Return: number of character printed
 */

int print_int(va_list arg)
{
	unsigned int divisor = 1, resp, i, charPrinted;
	int n = va_arg(arg, int);

	if (n < 0)
	{
		_putchar('-');
		charPrinted++;
		n *= -1;
	}

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;
	for (; divisor >= 1; n %= divisor, divisor /= 10, charPrinted++)
	{
		resp = n / divisor;
		_putchar('0' + resp);
	}

	return (charPrinted++);
}
