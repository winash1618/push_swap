#include "push_swap.h"

void delete_cond(new_num **from)
{
    if (*from == (*from)->next_num) {
        (*from) = NULL;
    } else {
        (*from)->prev_num->next_num = (*from)->next_num;
        (*from)->next_num->prev_num = (*from)->prev_num;
        (*from) = (*from)->next_num;
    }
}


static void other_nums(char **arg, new_num **num_first, new_num **num_last, new_num **num)
{
	int i;
	new_num *num_next;

	i = 2;
	while (arg[i] != NULL)
	{
		num_next = malloc(sizeof(new_num));
		num_next->data = ft_atoi(arg[i]);
		num_next->next_num = *num_first;
		(*num)->next_num = num_next;
		*num_last = *num;
		*num = (*num)->next_num;
		(*num)->prev_num = *num_last;
		i++;
	}
}

new_num *set_num_list(char **arg)
{
	new_num *num_last;
	new_num *num_first;
	new_num *num = malloc(sizeof(new_num));

	if (!num)
		return (NULL);
	num->data = ft_atoi(arg[1]);
	num->prev_num = num;
	num->next_num = num;
	num_first = num;
	other_nums(arg, &num_first, &num_last, &num);
	num_last = num;
	num = num->next_num;
	num->prev_num = num_last;
	return (num);
}

int ft_lstsize(new_num *lst)
{
	int i = 1;
	new_num *num_first = lst;
	if (lst == NULL)
		return (0);
	lst = lst->next_num;
	while (lst != num_first)
	{
		lst = lst->next_num;
		i++;
	}
	return (i);
}