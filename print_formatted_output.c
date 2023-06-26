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
<<<<<<< HEAD
	int flag = 0;
	printf_op_t fmt_op[] = 
	{
=======
	printf_op_t fmt_op[] = {
>>>>>>> d45f50aba56af67a4577a805992f34cbf3eded25
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\n', print_newline},
		{'\0', NULL}
	};
	int i;

	for (i = 0; fmt_op[i].c != '\0'; i++)
	{
		if (fmt_op[i].c == id)
		{
			c_printed = fmt_op[i].write_func(ap_list);
<<<<<<< HEAD
			flag = 1;
			break;
=======
>>>>>>> d45f50aba56af67a4577a805992f34cbf3eded25
		}
	}
	if (flag)
		return (c_printed);
	return (write(1, &id, 1));
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
<<<<<<< HEAD
=======

>>>>>>> d45f50aba56af67a4577a805992f34cbf3eded25
	UNUSED(ap_list);
	return (write(1, "%%", 1));
}

/**
 * print_newline - print newline to the stdout
 * @ap_list: pointer to the list of argument
 * Return: number of characters written
 */
int print_newline(va_list ap_list)
{

	UNUSED(ap_list);
	return (write(1, "\n", 1));
}

/**
 * print_string - print string to stdout
 * @ap_list: pointer to the list of argument
 * Return: number of characters printed
 */

int print_string(va_list ap_list)
{
	char *str;
	int length = 0;

	str = va_arg(ap_list, char *);
	if (!str)
		return (-1);
	while (str[length] != '\0')
		length++;
	return (write(1, str, length));
}
