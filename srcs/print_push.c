#include "push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_put_endl("pa");
}

void pb(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_put_endl("pb");
}