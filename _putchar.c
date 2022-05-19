#include <unistd.h>

/**
 * _putchar - prints all formats
 * @c: character
 * Return: prints the character or -1 error.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
