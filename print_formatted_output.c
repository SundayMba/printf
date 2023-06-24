#include "main.h"

/**
 * replace_char - replace a placeholder char and print to stdout
 * @ap_list: pointer to the list of variable argument
 * @id: placeholder character to replace
 * Return: number of characters written
 */

int replace_char(va_list ap_list, char id)
{
	int c_printed = 0;
	printf_op_t fmt_op[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};
	int i;

	for (i = 0; fmt_op[i].c != '\0'; i++)
	{
		if (fmt_op[i].c == id)
		{
			c_printed = fmt_op[i].write_func(ap_list);
			break;
		}
	}
	return (c_printed);
}


/**
 * print_char - print characters to stdout
 * @ap_list: pointer to the list of argument
 * Return: number of characters written
 */
int print_char(va_list ap_list)
{
	char c;

	c = va_arg(ap_list, int);
	return (write(1, &c, 1));
}

/**
 * print_percent - print percentage sign to the stdout
 * @ap_list: pointer to the list of argument
 * Return: number of characters written
 */
int print_percent(va_list ap_list)
{
	UNUSED(ap_list);
	return (write(1, "%%", 1));
}

/**
 * print_string - print string to stdout
 * @ap_list: pointer to the list of argument
 * Return: number of characters printed
 */

int print_string(va_list ap_list)
{
	char *str;
	int index = 0;

	str = va_arg(ap_list, char *);
	if (str == NULL)
		return (-1);
	while (str[index] != '\0')
		index++;
	return (write(1, str, index));
}
