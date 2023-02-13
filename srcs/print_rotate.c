#include "push_swap.h"

void ra(t_stack **stack)
{
	rotate(stack);
	ft_putendl_fd("ra", 1);
}

void rb(t_stack **stack)
{
	rotate(stack);
	ft_putendl_fd("rb", 1);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}