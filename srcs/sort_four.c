#include "push_swap.h"

void sort_four(t_stack **s_a, t_stack **s_b, t_list **moves)
{
	// ft_dlstprint(*s_a);
	do_best_rotate(s_a, moves);
	pb(s_a, s_b, moves);
	sort_three(s_a,	moves);
	pa(s_b, s_a, moves);
	// ft_dlstprint(*s_a);
}

