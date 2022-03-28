#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define FIRST_NUM (*l_a)->data
# define SECOND_NUM (*l_a)->next_num->data
# define THIRD_NUM (*l_a)->prev_num->data

typedef struct nums
{
    int data;
	int rank;
    struct nums *next_num;
    struct nums *prev_num;
} new_num;

void	big_sort(new_num **a, new_num **b);
void delete_cond(new_num **from);
new_num *set_num_list(char **arg);
int ft_lstsize(new_num *lst);
size_t	ft_strlen(const char *s);
int	ft_atoi(const char *str);
int is_sorted_list(new_num *lst, int len);
void s_action(new_num **lst);
void p_action(new_num **src, new_num **dst, char *str);
void r_action(new_num **lst, char *str);
void rr_action(new_num **lst, char *str);
int get_max(new_num *lst);
void rank_list (int len, char **av, new_num **lst);
void five_sort(new_num **l_a, new_num **l_b, int len);
int get_min(new_num *lst);

#endif