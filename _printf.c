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
	unsigned int j, sum = 0;
	char *p;
	specifier ops[] = {{"c", op_c},
		{"s", op_s},
		{"d", op_i},
		{"i", op_i},
		{"%", op_p}};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && !format[1] == '\0' && !format[2])
		return (-1);
	va_start(ptr, format);
	for (p = (char *)format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			for (j = 0; j < 5; j++)
			{
				if (ops[j].op[0] == *p)
				{
					sum += ops[j].f(ptr);
					break;
				}
			}
		}
		else
		{
			_putchar(*p);
			sum++;
		}
	}
	va_end(ptr);
	return (sum);
}
