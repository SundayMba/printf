#include "main.h"

/**
 * replace_char - replace a placeholder char and print to stdout
 * @ap_list: pointer to the list of variable argument
 * @id: placeholder character to replace
 * Return: number of characters written
 */

int replace_char(va_list ap_list, char id)
{
	printf_op_t fmt_op[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary},
		{'o', print_octal}, {'x', print_hex_lower},
		{'X', print_hex_upper}, {'u', print_unsigned}, {'\0', NULL}
	};
	int i, len = 0;

	for (i = 0; fmt_op[i].c != '\0'; i++)
		if (fmt_op[i].c == id)
			return (fmt_op[i].write_func(ap_list));
	if (fmt_op[i].c == '\0')
	{
		if (id == '\0')
			return (-1);
		len += write(1, "%%", 1);
		len += write(1, &id, 1);
		return (len);
	}
	return (-1);
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
	int i = 0;

	str = va_arg(ap_list, char *);
	if (str == NULL)
	{
		str = "(null)";
		while (str[i])
			i++;
		return (write(1, str, i));
	}
	while (str[i])
		i++;
	return (write(1, str, i));
}
/**
 * print_int - print int
 * @ap: pointer to int argument
 * Return: printed number
 */

int print_int(va_list ap)
{
	long int d, neg = 0;
	char *str;

	d = va_arg(ap, int);
	if (d < 0)
	{
		neg += write(1, "-", 1);
		d = ((-1) * d);
	}
	return (conv_print_int(d) + neg);
}
