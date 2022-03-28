#include "push_swap.h"

void two_sort(new_num **l_a)
{
	if ((*l_a)->data > (*l_a)->next_num->data)
		s_action(l_a);
}
void three_sort(new_num **l_a, new_num **l_b, int len)
{
	int min = get_min(*l_a);

	if (len == 3)
	{
		if ((*l_a)->next_num->data == min)
			s_action(l_a);
		else if ((*l_a)->prev_num->data == min)
			rr_action(l_a, "rra");
		p_action(l_a, l_b, "pb");
	}
	two_sort(l_a);
}

void four_sort(new_num **l_a, new_num **l_b, int len)
{
	int min = get_min(*l_a);

	if (len == 4)
	{
		if (min == (*l_a)->next_num->data)
			s_action(l_a);
		else if (min == (*l_a)->next_num->next_num->data)
		{
			r_action(l_a, "ra");
			s_action(l_a );
		}
		else if (min == (*l_a)->prev_num->data)
			rr_action(l_a, "rra");
		p_action(l_a, l_b, "pb");
		len--;
	}
	three_sort(l_a, l_b, len);
}

void five_sort(new_num **l_a, new_num **l_b, int len)
{
	int min = get_min(*l_a);
	
	if (len == 5)
	{
		if (min == (*l_a)->next_num->data)
			s_action(l_a);
		else if (min == (*l_a)->next_num->next_num->data)
		{
			r_action(l_a, "ra");
			s_action(l_a);
		}
		else if (min == (*l_a)->prev_num->data)
			rr_action(l_a, "rra");
		else if (min == (*l_a)->prev_num->prev_num->data)
		{
			rr_action(l_a, "rra");
			rr_action(l_a, "rra");
		}
		p_action(l_a, l_b, "pb");
		len--;
	}
	four_sort(l_a, l_b, len);
	while (*l_b != NULL)
		p_action(l_b, l_a, "pa");
}

