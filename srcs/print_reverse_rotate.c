#include "push_swap.h"

void rra(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rra", 1);
}

void rrb(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rrb", 1);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}