#include "main.h"

/**
 * op_c - Print character .
 * @form: name va_list
 *
 * Return: No.of printed bytes.
 */

int op_c(va_list form)
{
	int ch, counter = 0;

	ch = va_arg(form, int);
	_putchar(ch);
	return (counter++);
}

/**
 * op_p - Print percentage sign.
 * @form: name va_list
 *
 * Return: No.of printed bytes.
 */

int op_p(va_list form)
{
	int counter = 0;
	(void)form;

	_putchar('%');
	return (counter++);
}


/**
 * op_s -print string
 * @form: name va_list
 *
 * Return: no.of printed bytes.
 */
int op_s(va_list form)
{
	char *str;
	int counter = 0;

	str = va_arg(form, char *);
	while (*str)
	{
		_putchar(*str);
		str++;
		counter++;
	}
	return (counter);
}
/**
 * op_i - print numbers
 * @form: input
 * Return: counter
 */
int op_i(va_list form)
{
	int ch, counter = 1;

	ch = va_arg(form, int);
	counter = print_int(ch, counter);
	return (counter);
}
