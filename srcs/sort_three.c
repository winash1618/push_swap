#include "push_swap.h"

void sort_three(t_stack **s)
{
	if ((*s)->rank < (*s)->next->rank && (*s)->rank > (*s)->next->next->rank &&
		(*s)->next->rank > (*s)->next->next->rank)
	{
		ra(s);
		sa(s);
	}
	else if ((*s)->rank > (*s)->next->rank && (*s)->rank < (*s)->next->next->rank)
	{
		if ((*s)->next->rank >(*s)->next->next->rank)
			sa(s);
		else
			ra(s);
	}
	else if ((*s)->rank < (*s)->next->rank && (*s)->rank < (*s)->next->next->rank)
	{
		if ((*s)->next->rank > (*s)->next->next->rank)
		{
			sa(s);
			ra(s);
		}
		else
			rra(s);
	}
}