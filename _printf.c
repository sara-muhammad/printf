#include "main.h"

/**
 * _printf - print the output according to a format.
 * @format: pointer to a list of arguments
 *
 * Return: no.of printed bytes.
 */

int _printf(const char *format, ...)
{
	va_list ptr;
	unsigned int sum = 0, i = 0, j;
	specifier ops[] = {
		{"%c",op_c}, 
		{"%%",op_p},
		{"%s",op_s},
		{"%d",op_i},
		{"%i",op_i},
		};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(ptr,format);
	while(format[i])
	{
		for (j = 0; j < 5; j++)
		{
			if (format[i] == ops[j].op[0] && format[i+1] == ops[j+1].op[1])
			{
				sum += ops[j].f(ptr);
				i += 2;
			}
		}
		while (format[i])
		{
			_putchar(format[i]);
			i++;
			sum++;
		}	
	}
	va_end(ptr);
	return (sum);
}
