#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 * Return: success
 */

int main(void)
{
	char c  = 'b';
	int n, len, len2;
	char *name = "sunday mba";

	n = printf("hello %s, my age is %c %k %s\n", "sunday", '3');
	printf("printed: %d\n", n);
	/*n = printf("c: %c\n");
	printf("printed: %d\n", n);
	n = printf("s:%s\n");
	printf("printed: %d\n", n);
	n = printf("p %%\n");
	printf("printed: %d\n", n);*/
	

	n = _printf("hello %s, my age is %c %k %s\n", "sunday", '9');
	printf("printed: %d\n", n);
	/*n = _printf("c: %c%c\n", c, '%');
	printf("printed: %d\n", n);
	n = _printf("s:%s\n", name);
	printf("printed: %d\n", n);
	n = _printf("p %%\n");
	printf("printed: %d\n", n);*/

	/*len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("Length:[%d, %i]\n", len, len);*/

	return (0);
}


