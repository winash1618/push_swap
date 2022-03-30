/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:55:56 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/29 17:41:21 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_cond(t_new **from)
{
	if (*from == (*from)->next_num)
	{
		(*from) = NULL;
	}
	else
	{
		(*from)->prev_num->next_num = (*from)->next_num;
		(*from)->next_num->prev_num = (*from)->prev_num;
		(*from) = (*from)->next_num;
	}
}

static void	other_nums(char **arg, t_new **num_first,
							t_new **num_last, t_new **num)
{
	int		i;
	t_new	*num_next;

	i = 2;
	while (arg[i] != NULL)
	{
		num_next = malloc(sizeof(t_new));
		num_next->data = ft_atoi(arg[i]);
		num_next->next_num = *num_first;
		(*num)->next_num = num_next;
		*num_last = *num;
		*num = (*num)->next_num;
		(*num)->prev_num = *num_last;
		i++;
	}
}

t_new	*set_num_list(char **arg)
{
	t_new	*num_last;
	t_new	*num_first;
	t_new	*num;

	num = malloc(sizeof(t_new));
	if (!num)
		return (NULL);
	num->data = ft_atoi(arg[1]);
	num->prev_num = num;
	num->next_num = num;
	num_first = num;
	other_nums(arg, &num_first, &num_last, &num);
	num_last = num;
	num = num->next_num;
	num->prev_num = num_last;
	return (num);
}

int	ft_lstsize(t_new *lst)
{
	int		i;
	t_new	*num_first;

	num_first = lst;
	i = 1;
	if (lst == NULL)
		return (0);
	lst = lst->next_num;
	while (lst != num_first)
	{
		lst = lst->next_num;
		i++;
	}
	return (i);
}
