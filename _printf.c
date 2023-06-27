#include "main.h"

/**
 * _printf - print a formatted output to the stdout stream
 * @format: formatted string specifier
 * @...: variable input argument
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	/* pointer to the var argument list */
	va_list ap_list;
	int c_index = 0, c_printed = 0, c_temp;

	if (format == NULL)
		return (-1);
	if (format[0] == '%' && !format[1])
		return (-1);
	if (format[0]  == '%' && format[1] == ' ' && !format[2])
		return (-1);
	/* initialize the pointer */
	va_start(ap_list, format);
	while (*format != '\0')
	{
		/* check for placeholder replacement */
		if (*format == '%')
		{
			/* replace and print to stdout */
			c_printed += replace_char(ap_list, *(++format));
		}
		else
		{
			c_printed += print_output(*format);
		}
		format++;
	}
	return (c_printed);
	va_end(ap_list);
}

/**
 * print_output - print char to stdout
 * @c: char to print
 * Return: number of printed char
 */

int print_output(char c)
{
	return (write(1, &c, 1));
}
