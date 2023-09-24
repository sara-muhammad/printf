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
	int sum = 0, i = 0, j, rsum = 0;
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
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			for (j = 0; j < 5; j++)
			{
				if (format[i + 1] == ops[j].op)
				{
					rsum += ops[j].f(ptr);
					if (sum == -1)
					return (-1);
					else
						sum += rsum;
					break; } }
			if (ops[j].op != format[i + 1])
				sum += no_op(format[i + 1]);
			i += 2; }
		else
		{
			_putchar(format[i]);
			i++;
			sum++; } }
	va_end(ptr);
	return (sum); 
}

