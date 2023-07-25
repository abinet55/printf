#ifndef o_printf
#define o_printf
#include <stdarg.h>
#include <stdio.h>

typedef struct specifier
{
  char *valid;
  int (*f)(va_list);
}specific;
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int _putchar(char c);
int print_percent(va_list args);
int (*get_func(char x))(va_list args);

#endif
