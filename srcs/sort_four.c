#include "push_swap.h"

void sort_four(t_stack **s_a, t_stack **s_b)
{
	// ft_dlstprint(*s_a);
	do_best_rotate(s_a);
	pb(s_a, s_b);
	sort_three(s_a);
	pa(s_b, s_a);
	// ft_dlstprint(*s_a);
}

