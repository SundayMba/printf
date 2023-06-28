#include "main.h"

/**
 * print_unsigned - print unsigend number
 * @ap_list: pointer to the variable list of argument
 * Return: count of number
 */

int print_unsigned(va_list ap_list)
{
	unsigned int n = va_arg(ap_list, unsigned int);

	return (conv_print_int((long int)n));
}

/**
 * conv_print_int - convert and print int to stdio
 * @n: int value
 * Return: count of byte printed
 */

int conv_print_int(long int n)
{
	/* count = 1 b/c atleast one int will be passed*/
	long int temp = n;
	int count = 1, i;
	char *str;

	while ((temp / 10))
	{
		count++;
		temp /= 10;
	}
	str = malloc(count);
	if (str == NULL)
		return (-1);
	for (i = count - 1; i >= 0; i--)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	count = write(1, str, count);
	free(str);
	return (count);
}
