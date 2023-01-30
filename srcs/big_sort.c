/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:55:45 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/30 07:13:58 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	best_rotate(t_new **lst, int pos,	int do_a)
{
	int	size;

	size = ft_lstsize(*lst);
	if (pos < size / 2)
	{
		while (pos > 0)
		{
			if (do_a)
				r_action(lst, "ra");
			else
				r_action(lst, "rb");
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			if (do_a)
				rr_action(lst, "rra");
			else
				rr_action(lst, "rrb");
			pos++;
		}
	}
}

static int	find_less(t_new *lst, int part)
{
	int		i;
	int		z;
	t_new	*new;

	i = 0;
	new = lst;
	z = new->rank;
	while (new->next_num->rank != z)
	{
		if (new->rank <= part)
			break ;
		++i;
		new = new->next_num;
	}
	return (i);
}

static int	find_biggest(t_new *lst)
{
	int		i;
	int		largest;
	t_new	*new;

	new = lst;
	i = 0;
	largest = get_max(lst);
	while (1)
	{
		if (new->data == largest)
			break ;
		++i;
		new = new->next_num;
	}
	return (i);
}

void	push_back_all(t_new **a, t_new **b, int i)
{
	int	pos;

	while (i > 0)
	{
		pos = find_biggest(*b);
		best_rotate(b, pos, 0);
		p_action(b, a, "pa");
		i--;
	}
}

void	big_sort(t_new **a, t_new **b)
{
	int	size;
	int	part;
	int	i;
	int	pos;

	size = ft_lstsize(*a);
	part = 0;
	i = 1;
	while (*a != NULL)
	{
		if (size <= 100)
			part += size / 5;
		else
			part += size / 11 - 2;
		while (i <= part)
		{
			if (*a == NULL)
				break ;
			pos = find_less(*a, part);
			best_rotate(a, pos, 1);
			p_action(a, b, "pb");
			++i;
		}
	}
	push_back_all(a, b, i - 1);
}
