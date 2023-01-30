/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:57:56 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/30 06:51:10 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	two_sort(t_new **l_a)
{
	if ((*l_a)->data > (*l_a)->next_num->data)
		s_action(l_a);
}

static void	three_sort_left(t_new **l_a, int *i)
{
	if (i[0] < i[1] && i[0] < i[2] && i[1] > i[2])
	{
		s_action(l_a);
		r_action(l_a, "ra");
	}
	else if (i[0] > i[1] && i[0] < i[2] && i[1] < i[2])
		s_action(l_a);
	else if (i[0] < i[1] && i[0] > i[2] && i[1] > i[2])
		rr_action(l_a, "rra");
	else if (i[0] > i[1] && i[0] > i[2])
	{	
		if (i[1] < i[2])
			r_action(l_a, "ra");
		else
		{
			s_action(l_a);
			rr_action(l_a, "rra");
		}
	}
}

static void	three_sort(t_new **l_a, int len)
{
	int	i[3];

	i[0] = (*l_a)->data;
	i[1] = (*l_a)->next_num->data;
	i[2] = (*l_a)->prev_num->data;
	if (len == 3)
	{
		three_sort_left(l_a, i);
	}
	two_sort(l_a);
}

static void	four_sort(t_new **l_a, t_new **l_b, int len)
{
	int	min;

	min = get_min(*l_a);
	if (len == 4)
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
		p_action(l_a, l_b, "pb");
		len--;
	}
	three_sort(l_a, len);
}

void	five_sort(t_new **l_a, t_new **l_b, int len)
{
	int	min;

	min = get_min(*l_a);
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
