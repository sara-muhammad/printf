#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct format - structure
 * @op: character pointer
 * @f: pointer to function
 * Description : it contains data of arguments
 */

typedef struct format
{
	char op;
	int (*f)(va_list ptr);
} specifier;

int _printf(const char *format, ...);
int _putchar(char c);
int op_p(va_list form);
int op_c(va_list form);
int op_s(va_list form);
int op_i(va_list form);
int print_int(int n, int counter);
#endif
