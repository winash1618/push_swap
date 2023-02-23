#include "push_swap.h"

int ft_dlstsize(t_stack *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int ft_dlstrank_sum(t_stack *stack)
{
	int sum;

	sum = 0;
	while (stack)
	{
		sum += stack->rank;
		stack = stack->next;
	}
	return (sum);
}

void ft_dlstprint(t_stack *stack)
{
	t_stack *tmp;

	printf("*********************************************\n");
	tmp = stack;
	while (tmp)
	{
		printf("stack: %d, rank: %d\n", tmp->content, tmp->rank);
		tmp = tmp->next;
	}
	printf("*********************************************\n");
}

int ft_dlstsum(t_stack *stack)
{
	int sum;

	sum = 0;
	while (stack)
	{
		sum += stack->rank;
		stack = stack->next;
	}
	return (sum);
}