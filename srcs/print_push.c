#include "push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b, t_list **move_stack)
{
	push(stack_a, stack_b);
	ft_lstadd_back(move_stack, ft_lstnew("pa"));
}

void pb(t_stack **stack_b, t_stack **stack_a, t_list **move_stack)
{
	push(stack_b, stack_a);
	ft_lstadd_back(move_stack, ft_lstnew("pb"));
}