#include "push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
}

void pb(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
}