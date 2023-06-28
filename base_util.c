#include "main.h"

/**
 * base_n_conver - convert and print corresp. base to stdio
 * @n: number to print
 * @base: base to print
 * @h: hexadecimal value
 * Return: count of byte printed
 */

int base_n_conver(unsigned int n, int base, char h)
{
	unsigned int rem;
	char c;
	char *small_hex = "0123456789abcdef";
	char *big_hex = "0123456789ABCDEF";
	char *ptr;

	ptr = (h == 'x') ? small_hex : big_hex;
	/* using recursion for base conversion */
	if (base != 16)
	{
		if ((n / base) == 0)
		{
			rem = n % base;
			c = rem + '0';
			return (write(1, &c, 1));
		}
		rem = n % base;
		n = n / base;
		c = rem + '0';
		return (base_n_conver(n, base, h) + write(1, &c, 1));
	}
	else
	{
		if ((n / base) == 0)
		{
			rem = n % base;
			c = ptr[rem];
			return (write(1, &c, 1));
		}
		rem = n % base;
		n = n / base;
		c = ptr[rem];
		return (base_n_conver(n, base, h) + write(1, &c, 1));
	}
}

/**
 * print_binary - print binary
 * @ap_list: pointer to integer
 * Return: int rep. converted number
 */

int print_binary(va_list ap_list)
{
	unsigned int n = va_arg(ap_list, unsigned int);

	return (base_n_conver(n, 2, 'x'));
}

/**
 * print_hex_lower - print small letter hex
 * @ap_list: variable list of argument
 * Return: count of printed number
 */
int print_hex_lower(va_list ap_list)
{
	unsigned int n = va_arg(ap_list, unsigned int);

	return (base_n_conver(n, 16, 'x'));
}

/**
 * print_hex_upper - print big letter hex
 * @ap_list: variable list of argument
 * Return: count of printed number
 */
int print_hex_upper(va_list ap_list)
{
	unsigned int n = va_arg(ap_list, unsigned int);

	return (base_n_conver(n, 16, 'X'));
}

/**
 * print_octal - print octal letter
 * @ap_list: variable list of argument
 * Return: count of printed number
 */
int print_octal(va_list ap_list)
{
	unsigned int n = va_arg(ap_list, unsigned int);

	return (base_n_conver(n, 8, 'x'));
}
