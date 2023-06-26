#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
int print_c (int c)
{
	return (write(1, &c, 1));
}
int print_s(char *s)
{
	int n = 0;
	
	while (*s)
	{
		print_c((int)*s);
		++n;
		++s;
	}
	return (n);
}
/**int print_d(long a, int base)
{
	int i = 0;
	char *s;
	s = "0123456789abcdef";
	if (a < 0)
	{
		write(1, "-", 1);
		return (print_d(-a, base) +1);
	}
	else if (a < base)
		return (print_c(s[a]));
	else
	{
		i = print_d(a / base, base);
		return(i + print_d(a % base), base);
	}
}*/









int print_f(char fspecifier, va_list ap)
{
	int count = 0;

	if (fspecifier == 'c')
		count+= print_c(va_arg(ap, int));
	else if (fspecifier == 's')
		count+= print_s(va_arg(ap, char*));
/**	else if (fspecifier == 'd')
		count+= print_d((long)va_arg(ap, int), 10);
	else if (fspecifier == 'i')
		count+= print_d(va_arg(ap, int), 10);*/
	else
		count+= write(1, &fspecifier, 1);
	return (count);
}







int _printf(const char *format, ...)
{
	int num = 0 ;
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start (ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			num+= print_f(* (++format), ap);
		else
			num+= write (1, format, 1);
		++format;
	}
	va_end(ap);
	return (num);
}
