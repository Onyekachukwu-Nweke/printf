#include "main.h"

/**
 * print_unsignedToBinary - function that prints unsigned int
 * to binary
 * @arg: va_list argument
 * Return: num of characters printed
 */

int print_unsignedToBinary(va_list arg)
{

	unsigned int n = va_arg(arg, unsigned int);
	unsigned int printed;

	print_binary(n, &printed);

	return (printed);
}
