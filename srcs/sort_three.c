#include "push_swap.h"

void sort_three(t_stack **s)
{
	// ft_dlstprint(*s);
	if ((*s)->rank < (*s)->next->rank && (*s)->rank > (*s)->next->next->rank &&
		(*s)->next->rank > (*s)->next->next->rank)
		ra(s);
	else if ((*s)->rank > (*s)->next->rank && (*s)->rank < (*s)->next->next->rank)
	{
		if ((*s)->next->rank > (*s)->next->next->rank)
			rra(s);
		else
			sa(s);
	}
	else if ((*s)->rank < (*s)->next->rank && (*s)->rank < (*s)->next->next->rank &&
		(*s)->next->rank > (*s)->next->next->rank)
	{
		ra(s);
		sa(s);
	}
	else if ((*s)->rank > (*s)->next->rank && (*s)->rank > (*s)->next->next->rank)
	{
		if ((*s)->next->rank > (*s)->next->next->rank)
		{
			sa(s);
			ra(s);
		}
		else
			rra(s);
	}
	// ft_dlstprint(*s);
}
