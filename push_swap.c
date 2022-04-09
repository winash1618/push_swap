/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:56:40 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/09 14:28:57 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_nums(char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
		i++;
	return (--i);
}

static void	ft_free(t_new **me)
{
	t_new	*first;

	while (*me != NULL)
	{
		first = *me;
		delete_cond(me);
		free(first);
	}
}

static char	**splited(char **av)
{
	int		i;
	int		j;
	char	*av0;
	char	**ag;

	j = 0;
	i = 0;
	av0 = av[0];
	ag = ft_split(av[1], ' ');
	while (ag[i])
		i++;
	av = (char **)malloc(sizeof(char *) * (i + 2));
	av[0] = av0;
	while (i--)
	{
		av[j + 1] = ag[j];
		j++;
	}
	free(ag);
	av[j + 1] = NULL;
	return (av);
}

static void	push_swap(t_new **me, int len)
{
	t_new	*lst;

	lst = NULL;
	if (!is_duplicate(*me, len))
	{
		if (!is_sorted_list(*me, len) && len > 5)
			big_sort(me, &lst);
		else if (!is_sorted_list(*me, len))
			five_sort(me, &lst, len);
	}
}

int	main(int ac, char **av)
{
	int		len;
	t_new	*me;
	int		flag;

	len = ac - 1;
	flag = 0;
	if (len == 1)
	{
		av = (char **)splited(av);
		len = count_nums(av);
		flag = 1;
	}
	if (is_string_number(av, len) && len > 0 && is_integer(av, len, flag))
	{
		me = set_num_list(av);
		rank_list(len, av, &me);
		push_swap(&me, len);
		ft_free(&me);
	}
	ft_free1(av, flag);
	return (0);
}
