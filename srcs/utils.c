#include "push_swap.h"

char **split_then_free(char *s, char **(*f)(const char *, char))
{
	char **str;

	str = f(s, ' ');
	free(s);
	return (str);
}

int	ft_atoi_modified(const char *str, char **av)
{
	int				count;
	unsigned long	sum;

	count = 1;
	sum = 0;
	sum = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count = -count;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
		if ((sum > 2147483648 && count == -1) || (sum > 2147483647 && count == 1))
			ft_atoi_exit(av);
	}
	return (sum * count);
}

void check_range_error(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_atoi_modified(str[i], str);
}