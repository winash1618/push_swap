#include "push_swap.h"

void swap(t_stack **stack)
{
	t_stack *temp;

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
}

void rotate(t_stack **stack)
{
	t_stack *temp;

	temp = ft_dlst_last(*stack);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
}

void reverse_rotate(t_stack **stack)
{
	t_stack *temp;

	temp = ft_dlst_last(*stack);
	temp->next = *stack;
	(*stack)->prev = temp;
	(*stack)->next->prev = NULL;
	(*stack)->next = NULL;
}

void push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	temp = ft_dlst_last(*stack_a);
	temp->prev->next = NULL;
	temp->prev = NULL;
	ft_dlstadd_back(stack_b, temp);
}