#include "push_swap.h"

void rra(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putendl("rra");
}

void rrb(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putendl("rrb");
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl("rrr");
}