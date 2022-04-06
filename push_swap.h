/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:56:54 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/05 14:03:31 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct nums
{
	int			data;
	int			rank;
	struct nums	*next_num;
	struct nums	*prev_num;
}	t_new;

void	big_sort(t_new **a, t_new **b);
void	delete_cond(t_new **from);
t_new	*set_num_list(char **arg);
int		ft_lstsize(t_new *lst);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		is_sorted_list(t_new *lst, int len);
void	s_action(t_new **lst);
void	p_action(t_new **src, t_new **dst, char *str);
void	r_action(t_new **lst, char *str);
void	rr_action(t_new **lst, char *str);
int		get_max(t_new *lst);
void	rank_list(int len, char **av, t_new **lst);
void	five_sort(t_new **l_a, t_new **l_b, int len);
int		get_min(t_new *lst);
int		is_string_number(char **av, int len);
int		ft_isdigit(int c);
int		is_duplicate(t_new *lst, size_t len);
int		is_integer(char **av, size_t len);
int		ft_atoi_dup(const char *str);
int		is_atoi_err(const char *str);
char	**ft_split(char const *s, char c);

#endif
