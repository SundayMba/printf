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
	int c_printed = 0, index = 0, temp = 0;

	if (format == NULL)
		return (-1);
	/* initialize the pointer */
	va_start(ap_list, format);
	while (format[index] != '\0')
	{
		/* check for placeholder replacement */
		if (format[index] == '%')
		{
			/* replace and print to stdout */
			index++;
			temp = replace_char(ap_list, format[index]);
			if (temp == -1)
				return (-1);
			c_printed += temp;
		}
		else
		{
			c_printed += print_output(format[index]);
		}
		index++;
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
