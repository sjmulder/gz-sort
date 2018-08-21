#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "asprintf.h"

int asprintf(char **s, const char *fmt, ...)
{
	va_list ap;
	int n;

	va_start(ap, fmt);
	n = vasprintf(s, fmt, ap);
	va_end(ap);

	return n;
}

int vasprintf(char **s, const char *fmt, va_list ap)
{
	int n;

	if ((n = vsnprintf(NULL, 0, fmt, ap)) == -1)
		return -1;
	if (!(*s = malloc(n+1)))
		return -1;
	if ((n = vsnprintf(*s, n+1, fmt, ap)) == -1) {
		free(*s);
		return -1;
	}

	return n;
}
