#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    /** ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;*/
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    len = _printf("percentage: %%\n");
    len2 = printf("percentage: %%\n");
    printf("Len:[%d]\n", len);
    printf("Len1:[%d]\n\n", len2);
    
    len = _printf("Number: %d, %i\n", 4034, 4034);
    len2 = printf("Number: %d, %i\n", 4034, 4034);
    printf("Len:[%d]\n", len);
    printf("Len1:[%d]\n", len2);
    
    len = -printf("Negative: %i, %d\n", -4034, -4034);
    len2 = printf("Negative: %i, %d\n", -4034, -4034);
    printf("Len:[%d]\n", len);
    printf("Len1:[%d]\n", len2);
    
    len = _printf("%");
    len2 = printf("%");
    printf("Len:[%d]n", len);
    printf("Len1:[%d]n", len2);

    len = _printf("A simple sentence%");
    len2 = _printf("\nA simple sentence%");
    printf("\nLen: [%d]\n", len);
    printf("Len1: [%d]\n\n", len2);
	
   /** len = -printf("long: %i, %d\n", 4545439394949595, 4545439394949595);
    len2 = printf("long: %i, %d\n", 4545439394949595, 4545439394949595);
    printf("Len:[%d]\n", len);
    printf("Len1:[%d]\n", len2);*/

    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    return (0);
}
