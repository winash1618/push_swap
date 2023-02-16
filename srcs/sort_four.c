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

void sort_four(t_stack **s_a, t_stack **s_b)
{
	if (find_best_rotate(*s_a))
		while ((*s_a)->rank != 0)
			ra(s_a);
	else
		while ((*s_a)->rank != 0)
			rra(s_a);
	pb(s_a, s_b);
	sort_three(s_a);
	pa(s_b, s_a);
}

