#include <unistd.h>
#include <string.h>

/**
 * write_char -write character
 * @c: character to be written
 * Return: 1
 */

int write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * write_string -write strings
 * @s: string to be written
 * Return: 1
 */

int write_string(char *s)
{
	int size = sizeof(char) * strlen(s);
	return (write(1, s, size));
}
