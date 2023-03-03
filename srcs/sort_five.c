#include "push_swap.h"

void sort_five_or_more_hard_way(t_stack **s_a, t_stack **s_b, t_list **moves)
{
	while (ft_dlstsize(*s_a) != 3)
	{
		do_best_rotate(s_a);
		pb(s_a, s_b, moves);
	}
	sort_three(s_a, moves);
	while (ft_dlstsize(*s_b) != 0)
		pa(s_b, s_a, moves);
}