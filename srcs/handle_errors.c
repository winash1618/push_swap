#include "push_swap.h"

void error_exit()
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

void error_stack_exit(t_stack **stack)
{
	ft_putstr_fd("Error\n", 1);
	ft_dlstclear(stack);
	exit(0);
}

void ft_atoi_exit(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}