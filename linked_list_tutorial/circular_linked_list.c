# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct nums
{
    int data;
    struct nums *next_num;
    struct nums *prev_num;
} new_num;

int	ft_atoi(const char *str)
{
	int	count;
	unsigned int	sum;

	count = 1;
	sum = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count = -count;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	if (sum > 2147483648 && count == -1)
		return (0);
	else if (sum > 2147483647 && count == 1)
		return (-1);
	return (sum * count);
}
void push_circular(new_num** head_ref, int new_data)
{
	new_num *new_node;
	new_node = malloc(sizeof(new_num));
	/* 1. allocate node */
	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. Make next of new node as head */
	new_node->next_num = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}
// initialising the structure.

new_num *init_num_list(char **arg)
{
	new_num *num_last;
	new_num *num_first;
	new_num *num;
	new_num *num_next;
	int i;

	num = malloc(sizeof(new_num));
	if (!num)
		return (NULL);
	num->data = ft_atoi(arg[1]);
	num->prev_num = num;
	num->next_num = num;
	num_first = num;

	i = 2;
	while (arg[i] != NULL)
	{
		num_next = malloc(sizeof(new_num));
		num_next->data = ft_atoi(arg[i]);
		num_next->next_num = num_first;
		num->next_num = num_next;
		num_last = num;
		num = num->next_num;
		num->prev_num = num_last;
		i++;
	}
	num_last = num;
	num = num->next_num;
	num->prev_num = num_last;
	return (num);
}

void other_nums(char **arg, new_num **num_first, new_num **num_last, new_num **num)
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
void s_action(new_num **lst)
{
	int temp1;
	int temp2;
	temp1 = (*lst)->data;
	*lst = (*lst)->next_num;
	temp2 = (*lst)->data;
	(*lst)->data = temp1;
	*lst = (*lst)->prev_num;
	(*lst)->data = temp2;
}
void p_action(new_num **lst1, new_num **lst2)
{
	int temp;

	temp = (*lst1)->data;
	(*lst1)->data = (*lst2)->data;
	(*lst2)->data = temp;
}
new_num *ft_lstnew(void *content)
{
	new_num *new_lst;

	new_lst = malloc(sizeof(new_num));
	new_lst->data = ft_atoi((char *)content);
	new_lst->next_num = new_lst;
	new_lst->prev_num = new_lst;
	return (new_lst);
}
void ft_lstadd_front(new_num **lst, new_num *new)
{
	(*lst)->next_num = new;
	(*lst)->prev_num = new;
	new->prev_num = (*lst);
	new->next_num = (*lst);
}
int ft_lstsize(new_num *lst)
{
	int i = 1;
	new_num *num_first = lst;

	lst = lst->next_num;
	while (lst != num_first)
	{
		lst = lst->next_num;
		i++;
	}
	return (i);
}

int main(int ac, char **av)
{
	new_num *me = set_num_list(av);
	//printf("%d", (me->next_num)->data);
	s_action(&me);
	//printf("%d", (me->next_num)->data);
	printf("%d", ft_lstsize(me));
}