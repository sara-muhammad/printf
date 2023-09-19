#include "main.h"
/**
 * print_int - print numbers
 * @n: number
 * @counter: number of digits
 * Return: counter
*/
int print_int(int n, int counter)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
		counter++;
	}
	if (n / 10 != 0)
		counter =  print_int(n / 10, ++counter);
	_putchar((n % 10) + '0');
	return (counter);
}

