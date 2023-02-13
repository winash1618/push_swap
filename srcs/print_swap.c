#include "push_swap.h"

void sa(t_stack **stack)
{
	swap(stack);
	ft_putendl_fd("sa", 1);
}

void sb(t_stack **stack)
{
	swap(stack);
	ft_putendl_fd("sb", 1);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}