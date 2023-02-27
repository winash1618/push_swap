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

int highest_level_count(t_stack *s_b)
{
	t_stack *tmp;
	int highest_level;
	int count;

	highest_level = s_b->level;
	count = 0;
	tmp = s_b;
	while (s_b)
	{
		if (s_b->level > highest_level)
			highest_level = s_b->level;
		s_b = s_b->next;
	}
	s_b = tmp;
	while (s_b)
	{
		if (s_b->level == highest_level)
			count++;
		s_b = s_b->next;
	}
	return (count);
}

int lowest_level_count(t_stack *s_a)
{
	t_stack *tmp;
	int lowest_level;
	int count;

	lowest_level = s_a->level;
	count = 0;
	tmp = s_a;
	while (s_a)
	{
		if (s_a->level < lowest_level)
			lowest_level = s_a->level;
		s_a = s_a->next;
	}
	printf("lowest_level = %d\n", lowest_level);
	s_a = tmp;
	while (s_a)
	{
		if (s_a->level == lowest_level)
			count++;
		s_a = s_a->next;
	}
	return (count);
}

int highest_level_rank_sum(t_stack *s_b)
{
	t_stack *tmp;
	int highest_level;
	int sum;

	highest_level = s_b->level;
	sum = 0;
	tmp = s_b;
	while (s_b)
	{
		if (s_b->level > highest_level)
			highest_level = s_b->level;
		s_b = s_b->next;
	}
	s_b = tmp;
	while (s_b)
	{
		if (s_b->level == highest_level)
			sum += s_b->rank;
		s_b = s_b->next;
	}
	return (sum);
}

int lowest_level_rank_sum(t_stack *s_a)
{
	t_stack *tmp;
	int lowest_level;
	int sum;

	lowest_level = s_a->level;
	sum = 0;
	tmp = s_a;
	while (s_a)
	{
		if (s_a->level < lowest_level)
			lowest_level = s_a->level;
		s_a = s_a->next;
	}
	s_a = tmp;
	while (s_a)
	{
		if (s_a->level == lowest_level)
			sum += s_a->rank;
		s_a = s_a->next;
	}
	return (sum);
}

int highest_level(t_stack *stack)
{
	t_stack *tmp;
	int highest_level;

	highest_level = stack->level;
	tmp = stack;
	while (stack)
	{
		if (stack->level > highest_level)
			highest_level = stack->level;
		stack = stack->next;
	}
	stack = tmp;
	return (highest_level);
}

int get_max(int num1, int num2)
{
	if (num1 > num2)
		return 1;
	return 0;
}

int get_min(int num1, int num2)
{
	if (num1 < num2)
		return 1;
	return 0;
}

int is_stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->rank < stack->next->rank)
			return 0;
		stack = stack->next;
	}
	return 1;
}

void sort_divide_and_conquer_a(t_stack **s_a, t_stack **s_b, int (*get_min_max)(int, int), t_list **moves)
{
	int rank_sum;
	int elem_count;
	int high_level;

	ft_dlstprint(*s_a);
	ft_dlstprint(*s_b);
	elem_count = highest_level_count(*s_a);
	rank_sum = highest_level_rank_sum(*s_a);
	high_level = highest_level(*s_a);
	int ra_count = 0;
	while (1)
	{
		(*s_a)->level += 1;
		if (get_min_max((*s_a)->rank, rank_sum/elem_count))
			pb(s_a, s_b, moves);
		else
		{
			ra(s_a, moves);
			ra_count++;
		}
		if ((*s_a)->level != high_level)
		{
			while (ft_dlstsize(*s_a) > 1 && ra_count--)
				rra(s_a, moves);
			break;
		}
	}
	if (ft_dlstsize(*s_a) && highest_level_count(*s_a) > 2)
		sort_divide_and_conquer_a(s_a, s_b, get_min, moves);
	if (ft_dlstsize(*s_a) && highest_level_count(*s_a) <= 2)
	{
		if (highest_level_count(*s_a) == 1)
			;
		else if ((*s_a)->rank > (*s_a)->next->rank)
			sa(s_a, moves);
	}
	if (ft_dlstsize(*s_b) && highest_level_count(*s_b) > 2)
		sort_divide_and_conquer_b(s_b, s_a, get_max, moves);
	if (ft_dlstsize(*s_b) && highest_level_count(*s_b) <= 2)
	{
		if (highest_level_count(*s_b) == 1)
			;
		else if ((*s_b)->rank < (*s_b)->next->rank)
			sb(s_b, moves);
		int highest_level = highest_level_count(*s_b);
		while (highest_level--)
			pa(s_b, s_a, moves);
	}
	ft_dlstprint(*s_a);
	ft_dlstprint(*s_b);
}


void sort_divide_and_conquer_b(t_stack **s_a, t_stack **s_b, int (*get_min_max)(int, int), t_list **moves)
{
	int rank_sum;
	int elem_count;
	int high_level;
	ft_dlstprint(*s_a);
	ft_dlstprint(*s_b);
	elem_count = highest_level_count(*s_a);
	rank_sum = highest_level_rank_sum(*s_a);
	high_level = highest_level(*s_a);
	int ra_count = 0;
	while (1)
	{
		(*s_a)->level += 1;
		if (get_min_max((*s_a)->rank, rank_sum/elem_count))
			pa(s_a, s_b, moves);
		else
		{
			rb(s_a, moves);
			ra_count++;
		}
		if ((*s_a)->level != high_level)
		{
			while (ft_dlstsize(*s_a) > 1 && ra_count--)
				rrb(s_a, moves);
			break;
		}
	}
	
	if (ft_dlstsize(*s_b) && highest_level_count(*s_b) > 2)
		sort_divide_and_conquer_a(s_b, s_a, get_min, moves);
	if (ft_dlstsize(*s_b) && highest_level_count(*s_b) <= 2)
	{
		if (highest_level_count(*s_b) == 1)
			;
		else if ((*s_b)->rank < (*s_b)->next->rank)
			sa(s_b, moves);
		int highest_level = highest_level_count(*s_b);
		while (highest_level--)
			pa(s_b, s_a, moves);
	}
	if (ft_dlstsize(*s_a) && highest_level_count(*s_a) > 2)
		sort_divide_and_conquer_b(s_a, s_b, get_max, moves);
	if (ft_dlstsize(*s_a) && highest_level_count(*s_a) <= 2)
	{
		if (highest_level_count(*s_a) == 1)
			;
		else if ((*s_a)->rank > (*s_a)->next->rank)
			sb(s_a, moves);
	}
	ft_dlstprint(*s_a);
	ft_dlstprint(*s_b);
}