#include "push_swap.h"

void sort_divide_and_conquer(t_stack **s_a, t_stack **s_b)
{
	t_stack *temp = *s_a;

	while (1)
	{
		if ((*s_a)->rank < ft_dlstsize(*s_a)/2)
		{
			if (temp == *s_a)
				temp = (*s_a)->next;
			pb(s_a, s_b);
		}
		else
			ra(s_a);
		if (temp == *s_a)
			break;
	}
	if (ft_dlstsize(*s_a) > 3)
	{
		while ((*s_a)->prev)
			(*s_a) = (*s_a)->prev;
		sort_divide_and_conquer(s_a, s_b);
	}
	if (ft_dlstsize(*s_a) == 3)
		sort_three(s_a);
	ft_dlstprint(*s_a);
	ft_dlstprint(*s_b);
	exit(0);
}