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
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};
	int i;

	for (i = 0; fmt_op[i].c != '\0'; i++)
		if (fmt_op[i].c == id)
			return (fmt_op[i].write_func(ap_list));
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
	int d, whn, count = 1, c, neg = 0;
	char *str;

	d = va_arg(ap, int);

	if (d < 0)
	{
		neg += write(1, "-", 1);
		d = -d;
	}
	whn = d;
	whn = whn / 10;
	while (whn)
	{
		whn = whn / 10;
		count++;
	}
	str = malloc(count);
	if (str == NULL)
		return (-1);
	c = count;
	while (count)
	{
		str[--count] = (d % 10) + '0';
		d = d / 10;
	}
	count = write(1, str, c) + neg;
	free(str);
	return (count);
}

/*
 * int print_int(int d)
{
	char c;
	int rem, count = 0;

	if (d < 0)
	{
		count += write(1, "-", 1);
		d = -d;
	}
	if ((d / 10) == 0)
	{
		rem = d % 10;
		c = rem + '0';
		count += write(1, &c, 1);
		return (count);
	}
	rem = d % 10;
	d = d / 10;
	count += print_int(d);
	c = rem + '0';
	count += write(1, &c, 1);
	return (count);
}
*/

