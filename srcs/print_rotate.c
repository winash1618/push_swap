#include "push_swap.h"

void ra(t_stack **stack, t_list **move_stack)
{
	rotate(stack);
	ft_lstadd_back(move_stack, ft_lstnew("ra"));
}

void rb(t_stack **stack, t_list **move_stack)
{
	rotate(stack);
	ft_lstadd_back(move_stack, ft_lstnew("rb"));
}

void rr(t_stack **stack_a, t_stack **stack_b, t_list **move_stack)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_lstadd_back(move_stack, ft_lstnew("rr"));
}