#include "push_swap.h"

void sa(t_stack **stack, t_list **move_stack)
{
	swap(stack);
	ft_lstadd_back(move_stack, ft_lstnew("sa"));
}

void sb(t_stack **stack, t_list **move_stack)
{
	swap(stack);
	ft_lstadd_back(move_stack, ft_lstnew("sb"));
}

void ss(t_stack **stack_a, t_stack **stack_b, t_list **move_stack)
{
	swap(stack_a);
	swap(stack_b);
	ft_lstadd_back(move_stack, ft_lstnew("ss"));
}