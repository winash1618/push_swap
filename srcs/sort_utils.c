#include "push_swap.h"

int find_best_rotate(t_stack *s)
{
	int i;
	int size;

	i = 0;
	size = ft_dlstsize(s);
	while (s)
	{
		if (s->rank == 0)
			break;
		s = s->next;
		i++;
	}
	if (i > size / 2)
		return 1;
	else
		return 0;
}

int get_min_rank(t_stack *s)
{
	int min;

	min = s->rank;
	while (s)
	{
		if (min > s->rank)
			min = s->rank;
		s = s->next;
	}
	return (min);
}

int get_max_rank(t_stack *s)
{
	int max;

	max = s->rank;
	while (s)
	{
		if (max < s->rank)
			max = s->rank;
		s = s->next;
	}
	return (max);
}

void do_best_rotate(t_stack **s)
{
	if (find_best_rotate(*s))
		while ((*s)->rank != get_min_rank(*s))
			rra(s);
	else
		while ((*s)->rank != get_min_rank(*s))
			ra(s);
}