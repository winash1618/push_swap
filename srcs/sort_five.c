#include "push_swap.h"

void sort_two(t_stack **s)
{
	if ((*s)->rank > (*s)->next->rank)
		sa(s);
}

void sort_five_or_more_hard_way(t_stack **s_a, t_stack **s_b)
{
	int count;

	// ft_dlstprint(*s_a);
	while (ft_dlstsize(*s_a) != 3)
	{
		do_best_rotate(s_a);
		pb(s_a, s_b);
	}
	count = 0;
	sort_three(s_a);
	while (ft_dlstsize(*s_b) != 0)
	{
		if (count == 3)
		{
			sort_three(s_a);
			count = 0;
		}
		pb(s_b, s_a);
		count++;
	}
	if (count == 3)
		sort_three(s_a);
	if (count == 2)
		sort_two(s_a);
	// ft_dlstprint(*s_a);
}