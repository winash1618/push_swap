#include "push_swap.h"

void rra(t_stack **stack, t_list **move_stack)
{
	reverse_rotate(stack);
	ft_lstadd_back(move_stack, ft_lstnew("rra"));
}

void rrb(t_stack **stack, t_list **move_stack)
{
	reverse_rotate(stack);
	ft_lstadd_back(move_stack, ft_lstnew("rrb"));
}

void rrr(t_stack **stack_a, t_stack **stack_b, t_list **move_stack)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_lstadd_back(move_stack, ft_lstnew("rrr"));
}