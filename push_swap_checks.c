/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:57:12 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/29 17:01:06 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_list(t_new *lst, int len)
{
	int	i;
	int	temp;

	i = 1;
	while (i < len)
	{
		temp = lst->data;
		lst = lst->next_num;
		if (temp > lst->data)
			return (0);
		i++;
	}
	return (1);
}
