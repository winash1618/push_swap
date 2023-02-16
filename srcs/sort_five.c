#include "push_swap.h"

void sort_five(t_stack **s_a, t_stack **s_b)
{
	int size;

	size = dlstsize(*s_a);
	while (dlstsize(*s_a) != 3)
	{
		if ((*s_a)->rank > size / 2)
			pb(s_a, s_b);
		else
			ra(s_a);
	}
	
}