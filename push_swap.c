/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:56:40 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/29 17:02:09 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	int		len;
	t_new	*me;
	t_new	*lst;

	i = 0;
	len = ac - 1;
	me = set_num_list(av);
	rank_list(len, av, &me);
	lst = NULL;
	if (!is_sorted_list(me, len) && len > 5)
		big_sort(&me, &lst);
	else if (!is_sorted_list(me, len))
		five_sort(&me, &lst, len);
}
