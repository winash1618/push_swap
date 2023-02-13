#include "push_swap.h"

char **split_then_free(char *s, char **(*f)(const char *, char))
{
	char **str;

	str = f(s, ' ');
	free(s);
	return (str);
}