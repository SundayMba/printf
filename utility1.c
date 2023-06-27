#include "main.h"

/**
 * binary_conversion - print in binary
 * @n: number to print
 * Return: count of byte printed
 */

int binary_conversion(unsigned int n)
{
	unsigned int rem;
	char c;

	if ((n / 2) == 0)
	{
		rem = n % 2;
		c = rem + '0';
		return (write(1, &c, 1));
	}
	rem = n % 2;
	n = n / 2;
	c = rem + '0';
	return (binary_conversion(n) + write(1, &c, 1));
}

/**
 * print_binary - print binary
 * @ap_list: pointer to integer
 * Return: int rep. converted number
 */

int print_binary(va_list ap_list)
{
	unsigned int n = va_arg(ap_list, unsigned int);

	return (binary_conversion(n));
}
