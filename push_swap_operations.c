/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:57:25 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/29 17:08:08 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_action(t_new **lst)
{
	int	i[4];

	write(1, "sa\n", 3);
	i[0] = (*lst)->data;
	i[2] = (*lst)->rank;
	*lst = (*lst)->next_num;
	i[1] = (*lst)->data;
	i[3] = (*lst)->rank;
	(*lst)->data = i[0];
	(*lst)->rank = i[2];
	*lst = (*lst)->prev_num;
	(*lst)->data = i[1];
	(*lst)->rank = i[3];
}

void	p_action(t_new **src, t_new **dst, char *str)
{
	t_new	*save;
	t_new	*stock;

	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	if (*src == NULL)
		return ;
	save = *src;
	delete_cond(src);
	if ((*dst) != NULL)
	{
		stock = (*dst)->prev_num;
		(*dst)->prev_num = save;
		(*dst)->prev_num->next_num = (*dst);
		(*dst)->prev_num->prev_num = stock;
		(*dst)->prev_num->prev_num->next_num = save;
		*dst = (*dst)->prev_num;
	}
	else
	{
		(*dst) = save;
		(*dst)->next_num = (*dst);
		(*dst)->prev_num = (*dst);
	}
}

void	r_action(t_new **lst, char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	(*lst) = (*lst)->next_num;
}

void	rr_action(t_new **lst, char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	(*lst) = (*lst)->prev_num;
}
