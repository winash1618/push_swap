#include "push_swap.h"

int is_sorted_list(new_num *lst, int len)
{
	int i;

	i = 1;
	while(i < len)
	{
		int temp = lst->data;
		lst = lst->next_num;
		if(temp > lst->data)
			return (0);
		i++;
	}
	return (1);
}