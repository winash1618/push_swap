/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:19:27 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/19 13:45:52 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_chunk(t_stack **s_a, t_stack **s_b, t_list **moves)
{
	int chunk_size = ft_dlstsize(*s_a) / 5;
	
	int i = 0;
	int j = 0;
	while (i < 5)
	{
		while (j < chunk_size)
		{
			
		}
		j += chunk_size;
	}
}
