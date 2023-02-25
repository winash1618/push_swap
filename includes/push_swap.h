/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:56:54 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/25 09:48:11 by mkaruvan         ###   ########.fr       */
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
	int				content;
	int				rank;
	int				level;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/*************************************************************/
/******************* validate_args.c *************************/
/*************************************************************/
int		validate_args(int argc, char **argv);
int		check_args_for_sign_error(int argc, char **argv);
int		check_args_for_non_digit_values(int argc, char **argv);
int		check_args_with_only_spaces(int argc, char **argv);

/**************************************************************/
/******************* handle_errors.c **************************/
/**************************************************************/
void	error_exit();
void	error_stack_exit(t_stack **stack);
void	ft_atoi_exit(char **str);

/**************************************************************/
/************************ dlst_ops.c **************************/
/**************************************************************/
t_stack	*ft_dlstnew(int content);
void	ft_dlstadd_back(t_stack **olst, t_stack *nlst);
void	ft_dlstadd_front(t_stack **olst, t_stack *nlst);
void	ft_dlstclear(t_stack **lst);
t_stack	*ft_dlstlast(t_stack *lst);

/**************************************************************/
/************************ dlst_utils.c ************************/
/**************************************************************/
int		ft_dlstsize(t_stack *lst);
int		ft_dlstrank_sum(t_stack *stack);
void	ft_dlstprint(t_stack *stack);
t_stack	*ft_dlstfirst(t_stack *stack);

/**************************************************************/
/************************ moves.c *****************************/
/**************************************************************/
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **stack_a, t_stack **stack_b);

/**************************************************************/
/********************* print_push.c ***************************/
/**************************************************************/
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);

/**************************************************************/
/****************** print_reverse_rotate.c ********************/
/**************************************************************/
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/**************************************************************/
/********************* print_rotate.c *************************/
/**************************************************************/
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);

/**************************************************************/
/************************ print_swap.c ************************/
/**************************************************************/
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);


/**************************************************************/
/********************* init_stack.c ***************************/
/**************************************************************/
char	*ft_strjoin_with_spaces(char const *s1, char const *s2);
char	*merge_args_with_spaces(int argc, char **argv);
void	add_ranks_to_each_nodes(t_stack *stack);
void	check_stack_for_duplicates(t_stack **stack);
void	init_stack(t_stack **stack, int argc, char **argv);

/*************************************************************/
/************************* utils.c ***************************/
/*************************************************************/
char	**split_then_free(char *s, char **(*f)(const char *, char));
int		ft_atoi_modified(const char *str, char **av);
void	check_range_error(char **str);

/*************************************************************/
/*********************** sort_three.c ************************/
/*************************************************************/
void sort_three(t_stack **s);

/*************************************************************/
/********************** sort_four.c **************************/
/*************************************************************/
void sort_four(t_stack **s_a, t_stack **s_b);

/*************************************************************/
/********************** sort_five.c **************************/
/*************************************************************/
void sort_five_or_more_hard_way(t_stack **s_a, t_stack **s_b);

/*************************************************************/
/********************** sort_utils.c *************************/
/*************************************************************/
void do_best_rotate(t_stack **s);
int find_best_rotate(t_stack *s);

/*************************************************************/
/*************** sort_divide_and_conquer.c *******************/
/*************************************************************/
// void sort_divide_and_conquer(t_stack **s_a, t_stack **s_b);
void sort_divide_and_conquer(t_stack **s_a, t_stack **s_b, int (*get_min_max)(int, int));
void sort_divide_and_conquer_a(t_stack **s_a, t_stack **s_b, t_stack *end);
void sort_divide_and_conquer_b(t_stack **s_a, t_stack **s_b, int (*get_min_max)(int, int));
int get_min(int num1, int num2);
int get_max(int num1, int num2);

#endif
