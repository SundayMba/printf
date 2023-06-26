#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#define UNUSED(x) (void)(x)

int _printf(const char *format, ...);
int print_output(char c);
int replace_char(va_list ap_list, char id);

/**
 * struct printf_op - defines a prototype for printing
 * @c: character to replace
 * @write-func: pointing to each printing function
 */
struct printf_op
{
	char c;
	int (*write_func)(va_list ap_list);
};
typedef struct printf_op printf_op_t;

int print_char(va_list);
int print_int(va_list);
int print_newline(va_list);
int print_string(va_list);
int print_float(va_list);
int print_percent(va_list);
int print_double(va_list);
int print_binary(int);
int print_hex_upper(va_list);
int print_hex_lower(va_list);
int print_octal(va_list);
int print_pointer(va_list);
int print_rot13string(va_list);

#endif
