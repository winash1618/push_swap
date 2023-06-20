#include "push_swap.h"

void sort_three(t_stack **s, t_list ** moves)
{
	if ((*s)->rank < (*s)->next->rank && (*s)->rank > (*s)->next->next->rank &&
		(*s)->next->rank > (*s)->next->next->rank)
		rra(s, moves);
	else if ((*s)->rank > (*s)->next->rank && (*s)->rank < (*s)->next->next->rank)
	{
		if ((*s)->next->rank > (*s)->next->next->rank)
			ra(s, moves);
		else
			sa(s, moves);
	}
	else if ((*s)->rank < (*s)->next->rank && (*s)->rank < (*s)->next->next->rank &&
		(*s)->next->rank > (*s)->next->next->rank)
	{
		rra(s, moves);
		sa(s, moves);
	}
	else if ((*s)->rank > (*s)->next->rank && (*s)->rank > (*s)->next->next->rank)
	{
		if ((*s)->next->rank > (*s)->next->next->rank)
		{
			sa(s, moves);
			rra(s, moves);
		}
		else
			ra(s, moves);
	}
}


