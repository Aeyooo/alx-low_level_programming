#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg>

/**
 * print_strings - Prints strings, followed by a new line.
 * @seperator: The string to be printed between strings
 * @n: The number of strings passed to the function
 * @...: A variable number of strings to be printed.
 *
 * Description: if seperators is NULL, it is not to be printed.
 * if one of the dtrings is NULL, (nil) is printed instead.
 */
void print_strings(const char *seperator, const unsigned int n, ...)
{
	va_list strings;
	char *str;
	unsigned int index;


	va _start(strings, n);

	for (index = 0; index < n; index++)
	{
		str = va_arg(strings, char*);
		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (index != (n - 1) && seperator != NULL)
			printf("%s", seperator);
	}

	print("\n");

	va_end(strings);
}
