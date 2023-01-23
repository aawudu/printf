#include "main.h"
/**
 * _printf - is a function prints based on provided format.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int mi = 0, ji, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
Here:
	while (format[mi] != '\0')
	{
		ji = 13;
		while (ji >= 0)
		{
			if (m[ji].id[0] == format[mi] && m[ji].id[1] == format[mi + 1])
			{
				len += m[ji].f(args);
				mi = mi + 2;
				goto Here;
			}
			ji--;
		}
		_putchar(format[mi]);
		len++;
		mi++;
	}
	va_end(args);
	return (len);
}
