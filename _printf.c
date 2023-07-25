#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include "main.h"
/**
* _printf - our own printf function
* @format: string
* Return: charactrs to be printed
*/

int _printf(const char *format, ...)
{
if (format != NULL)
{
int cc = 0, i;
int (*x)(va_list);
va_list args;
va_start(args, format);
i = 0;
if (format[0] == '%' && format[1] == '\0')
return (-1);
while (format != NULL && format[i] != '\0')
{
if (format[i] == '%')
{
if (format[i + 1] == '%')
{
cc = cc + _putchar(format[i]);
i = i + 2;
}
else
{
x = get_func(format[i + 1]);
if (x)
cc = cc + x(args);
else
cc = _putchar(format[i]) + _putchar(format[i + 1]);
i = i + 2;
}
}
else
{
cc = cc + _putchar(format[i]);
i++;
}
}
va_end(args);
return (cc);
}
return (-1);
}
