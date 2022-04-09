/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:57:12 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/09 12:06:30 by mkaruvan         ###   ########.fr       */
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

static int	string_checker(char **av, int len)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (len--)
	{
		if (!ft_isdigit(av[i][0]))
		{
			if (av[i][0] == '-' && ft_isdigit(av[i][1]))
				k = k * 1;
			else if ((av[i][0] == '+') && ft_isdigit(av[i][1]))
				k = k * 1;
			else
				k++;
		}
		i++;
	}
	return (k);
}

int	is_string_number(char **av, int len)
{
	int	k;

	k = string_checker(av, len);
	if (k > 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
		return (1);
}

int	is_duplicate(t_new *lst, size_t len)
{
	t_new	*dup;
	size_t	i;

	i = 0;
	dup = lst;
	lst = lst->next_num;
	while (dup != lst)
	{
		lst->rank += 1;
		i += lst->rank;
		lst = lst->next_num;
	}
	lst->rank += 1;
	i += lst->rank;
	if (i != len * (len + 1) / 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	is_integer(char **av, size_t len)
{
	int	i;
	int	k;
	int	j;

	i = 1;
	j = 0;
	while (len--)
	{
		k = ft_atoi(av[i]);
		if ((k == 0 || k == -1) && k != ft_atoi_dup(av[i]))
			j++;
		if (is_atoi_err(av[i]))
			j++;
		i++;
	}
	if (j > 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
		return (1);
}
