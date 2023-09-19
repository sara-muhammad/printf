#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct format - structure
 * @op: character pointer
 * @f: pointer to function
 * Description : it contains data of arguments
 */

typedef struct format
{
	char *op;
	int (*f)(va_list ptr);
} specifier;

int op_p(void);
int op_c(va_list form);
int op_s(va_list form);
int op_i(va_list form);
int _printf(const char *format, ...);
int _putchar(char c);
int print_int(int n,int counter);

#endif
