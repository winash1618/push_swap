/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:57:35 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/02 07:20:53 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_new *lst)
{
	int		temp;
	t_new	*lst2;

	temp = lst->data;
	lst2 = lst;
	lst = lst->next_num;
	while (lst != lst2)
	{
		if (temp > lst->data)
			temp = lst->data;
		lst = lst->next_num;
	}
	return (temp);
}

int	get_max(t_new *lst)
{
	int		temp;
	t_new	*lst2;

	temp = lst->data;
	lst2 = lst;
	lst = lst->next_num;
	while (lst != lst2)
	{
		if (temp < lst->data)
			temp = lst->data;
		lst = lst->next_num;
	}
	return (temp);
}

static void	ranker(int *arr1, int *arr2, t_new **lst, int len)
{
	int		i[2];
	t_new	*first_num;

	i[0] = 0;
	while (i[0] < len)
	{
		i[1] = 0;
		while (i[1] < len)
		{
			if (arr1[i[0]] > arr1[i[1]] && i[0] != i[1])
				arr2[i[0]] = arr2[i[0]] + 1;
			i[1]++;
		}
		i[0]++;
	}
	first_num = (*lst);
	i[0] = 0;
	while ((*lst)->next_num != first_num)
	{
		(*lst)->rank = arr2[i[0]];
		(*lst) = (*lst)->next_num;
		i[0]++;
	}
	(*lst)->rank = arr2[i[0]];
	(*lst) = (*lst)->next_num;
}

void	rank_list(int len, char **av, t_new **lst)
{
	int		i;
	int		*arr1;
	int		*arr2;

	i = 0;
	arr1 = malloc(sizeof(int) * len);
	arr2 = malloc(sizeof(int) * len);
	if (!arr1 && !arr2)
		return ;
	while (i < len)
	{
		arr1[i] = ft_atoi(av[i + 1]);
		arr2[i++] = 0;
	}
	ranker(arr1, arr2, lst, len);
	free(arr1);
	free(arr2);
}
