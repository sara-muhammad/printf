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

	specifier ops[] = {
		{"c", op_c},
		{"s", op_s},
		{"d", op_i},
		{"%", op_p},
		{"i", op_i},
		};

	va_start(ptr, format);
	for (p = (char *)format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			j = 0;	
			while (ops[j].op && ops[j].op != NULL)
			{
				if (ops[j].op[0] == *p)
				{
					sum += ops[j].f(ptr);
				}
			j++;
			}
		}
		else
		{
			while (*p)
			{
				_putchar(*p);
				p++;
				sum++;
			}
		}
	}
	va_end(ptr);
	return (sum);
}
