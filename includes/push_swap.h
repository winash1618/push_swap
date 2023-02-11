/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:56:54 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/11 05:37:47 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	int		content;
	int		rank;
	t_stack	*next;
	t_stack	*prev;
}			t_stack;

/*************************************************************/
/******************* validate_args.c *************************/
/*************************************************************/

int check_args(int argc, char **argv);
int check_args_for_sign_error(int argc, char **argv);
int check_args_for_non_digit_values(int argc, char **argv);
int	check_args_with_only_spaces(int argc, char **argv);

/**************************************************************/
/******************* handle_errors.c **************************/
/**************************************************************/
void error_exit();

/**************************************************************/
/******************* list_operations.c ************************/
/**************************************************************/
t_stack	*ft_dlstnew(int content);
void	ft_dlstadd_back(t_stack **olst, t_stack *nlst);
void	ft_dlstclear(t_stack **lst);
t_stack	*ft_dlstlast(t_stack *lst);
int		ft_dlstsize(t_stack *lst);

#endif
