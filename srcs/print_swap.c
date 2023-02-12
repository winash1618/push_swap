#include "push_swap.h"

void sa(t_stack **stack)
{
	swap(stack);
	ft_putendl("sa");
}

void sb(t_stack **stack)
{
	swap(stack);
	ft_putendl("sb");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl("ss");
}