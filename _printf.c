#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf -similar to inbuilt printf
 * @format: first arg
 * @...: variable args
 * Return: char count
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	char buffer[100];

	va_start(args, format);
	if (format)
	{
		while (format[i] != '\0')
		{
			if (format[i] != '%')
			{
				write_char(format[i]);
				i++;
			}
			else
			{
				switch (format[i + 1])
				{
					case 'c':
						write_char(va_arg(args, int));
						break;
					case 's':
						write_string(va_arg(args, char *));
						break;
					case 'i':
					case 'd':
						gcvt(va_arg(args, int), -1, buffer);
						write_string(buffer);
						break;
					case 'f':
						/**gcvt (float value, int ndigits, char * buf);*/
						gcvt(va_arg(args, double), 6, buffer);
						write_string(buffer);
						break;
					case '%':
						write_char(format[i + 1]);
						break;
					default:
						write_char(format[i]);
						write_char(format[i + 1]);
						break;
				}
				i += 2;
			}
		}
	}
	va_end(args);
	return (i);
}

