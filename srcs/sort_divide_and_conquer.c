#include "push_swap.h"

int get_initial_length(t_stack *s_a, t_stack *end)
{
	int elem_count;

	elem_count = 0;
	while (s_a != end)
	{
		elem_count++;
		s_a = s_a->next;
	}
	return (elem_count);
}

void sort_divide_and_conquer(t_stack **s_a, t_stack **s_b)
{
	int rank_sum;
	int elem_count;

	elem_count = ft_dlstsize(*s_a);
	rank_sum = ft_dlstsum(*s_a);
	printf("rank_sum = %d\n", rank_sum);
	printf("elem_count = %d\n", elem_count);
	ft_dlstprint(*s_a);
	ft_dlstprint(*s_b);
	t_stack *start;
	start = *s_a;
	while (1)
	{
		if ((*s_a)->rank <= rank_sum/elem_count)
		{
			printf("rank = %d\n", (*s_a)->rank);
			if (*s_a == start)
				start = (*s_a)->next;
			pb(s_a, s_b);
			continue;
		}
		else
		{
			printf("rank = %d\n", (*s_a)->rank);
			ra(s_a);
		}
		if (*s_a == start)
			break;
	}
	if (ft_dlstsize(*s_a) > 2)
	{
		printf("dlstlength = %d\n", ft_dlstsize(*s_a));
		sort_divide_and_conquer(s_a, s_b);
	}
	// if (ft_dlstsize(*s_a) == 2)
	// 	sort_two(s_a);
	ft_dlstprint(*s_a);
	ft_dlstprint(*s_b);
	exit(0);
}


void sort_divide_and_conquer_a(t_stack **s_a, t_stack **s_b, t_stack *end)
{
	t_stack *new_end;
	int elem_count;

	new_end = NULL;
	elem_count = get_initial_length(*s_a, end);
	while (1)
	{
		if ((*s_a)->rank < ft_dlstsize(*s_a)/2)
		{
			if (!new_end)
				new_end = *s_a;
			pb(s_a, s_b);
			elem_count--;
		}
		else
			ra(s_a);
		if (*s_a == end)
			break;
	}
	if (elem_count > 1)
	{
		sort_divide_and_conquer_a(s_a, s_b, ft_dlstlast(*s_a));
	}
	// if (ft_dlstsize(*s_a) == 2)
	// 	sort_two(s_a);
	ft_dlstprint(*s_a);
	ft_dlstprint(*s_b);
	exit(0);
}
