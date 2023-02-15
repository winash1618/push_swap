#include "push_swap.h"

int find_best_rotate(t_stack *s)
{
	int i;

	i = 0;
	while (s)
	{
		if(s->rank == 0)
			break;
		s = s->next;
		i++;
	}
	if (i >= dlstsize(s) / 2)
		return 1;
	else
		return 0;
}

void sort_four(t_stack **s)
{
	if (find_best_rotate();)
	{
		while ((*s)->rank == 0)
			ra(s);
	}
	else
	{
		while ((*s)->rank == 0)
			rra(s);
	}
	pb(s);
	sort_three(s);
	pa(s);
}

