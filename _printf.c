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
	unsigned int sum = 0, j;
	specifier ops[] = {
		{'c', op_c}, 
		{'%', op_p},
		{'s', op_s},
		{'d', op_i},
		{'i', op_i},
		{'\0', NULL}
		};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(ptr,format);
	while(*format)
	{

		if (*format == '%')
		{
			format++;
			for(j = 0; j <5; j++)
			{
				if (*format == ops[j].op)
				{
					sum += ops[j].f(ptr);
				}
			}
		format++;
		}
		else
		{
		_putchar(*format);
		format++;
		sum++;
		}
	}
	va_end(ptr);
	return (sum);
}

