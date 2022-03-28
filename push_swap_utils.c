#include "push_swap.h"

int get_min(new_num *lst)
{
	int temp;

	temp = lst->data;
	new_num *lst2 = lst;
	lst = lst->next_num;
	while (lst != lst2)
	{
		if (temp > lst->data)
			temp = lst->data;
		lst = lst->next_num;
	}
	return temp;
}

int get_max(new_num *lst)
{
	int temp;

	temp = lst->data;
	new_num *lst2 = lst;
	lst = lst->next_num;
	while (lst != lst2)
	{
		if (temp < lst->data)
			temp = lst->data;
		lst = lst->next_num;
	}
	return temp;
}

void rank_list (int len, char **av, new_num **lst)
{
	int	i;
	int	*arr1;
	int	*arr2;
	
	i = 0;
	arr1 = malloc(sizeof(int) * len);
	arr2 = malloc(sizeof(int) * len);
	while (i < len)
	{
		arr1[i] = ft_atoi(av[i + 1]);
		arr2[i++] = 0;
	}
	i = 0;
	while (i < len)
	{
		int j = 0;
		while (j < len)
		{
			if (arr1[i] > arr1[j] && i != j)
			{
				arr2[i] = arr2[i] + 1;
			}
			j++;
		}
		i++;
	}
	new_num *first_num = (*lst);
	i = 0;
	while ((*lst)->next_num != first_num)
	{
		(*lst)->rank = arr2[i];
		(*lst) = (*lst)->next_num;
		i++; 
	}
	(*lst)->rank = arr2[i];
	(*lst) = (*lst)->next_num;
	
}