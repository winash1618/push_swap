#include "push_swap.h"

void swap(t_stack **stack)
{
	t_stack *temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

void reverse_rotate(t_stack **stack)
{
	t_stack *temp;

	temp = ft_dlstlast(*stack);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}

void rotate(t_stack **stack)
{
	t_stack *temp;

	temp = ft_dlstlast(*stack);
	temp->next = *stack;
	(*stack)->prev = temp;
	temp = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp;
}

void push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (temp->next)
		temp->next->prev = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	ft_dlstadd_front(stack_b, temp);
}