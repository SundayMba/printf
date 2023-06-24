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
	/* initialize the pointer */
	va_start(ap_list, format);
	while (format[c_index] != '\0')
	{
		/* check for placeholder replacement */
		if (format[c_index] == '%')
		{
			/* replace and print to stdout */
			c_temp = replace_char(ap_list, format[++c_index]);
			if (c_temp == -1)
				break;
			c_printed += c_temp;
		}
		else
		{
			c_printed += print_output(format[c_index]);
		}
		c_index++;
	}
	return (c_printed);
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
