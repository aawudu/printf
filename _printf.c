#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/**
  * find_function - function that finds formats for _printf
  * calls the corresponding function.
  * @format: format (char, string, int, decimal)
  * Return: NULL or function associated ;
  */
int (*find_function(const char *format))(va_list)
{
	unsigned int p = 0;
	code_f find_f[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_dec},
		{"r", print_rev},
		{"b", print_bin},
		{"u", print_unsig},
		{"o", print_octal},
		{"x", print_x},
		{"X", print_X},
		{"R", print_rot13},
		{NULL, NULL}
	};
	while (find_f[p].sc)
	{
		if (find_f[p].sc[0] == (*format))
			return (find_f[p].f);
		p++;
	}
	return (NULL);
}
/**
  * _printf - function gives output according to a format.
  * @format: format (char, string, int, decimal)
  * Return: size the output
  */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int p = 0, printcount = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[p])
	{
		while (format[p] != '%' && format[p])
		{
			_putchar(format[p]);
			printcount++;
			p++;
		}
		if (format[p] == '\0')
			return (printcount);
		f = find_function(&format[p + 1]);
		if (f != NULL)
		{
			printcount += f(ap);
			p += 2;
			continue;
		}
		if (!format[p + 1])
			return (-1);
		_putchar(format[p]);
		printcount++;
		if (format[p + 1] == '%')
			p += 2;
		else
			p++;
	}
	va_end(ap);
	return (printcount);
}
