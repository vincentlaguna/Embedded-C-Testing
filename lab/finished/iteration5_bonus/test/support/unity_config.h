#include <stdio.h>

extern void print_uart0(const char s);

#define UNITY_OUTPUT_CHAR(a) print_uart0(a)
