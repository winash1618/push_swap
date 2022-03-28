#include "push_swap.h"

int main(int ac, char **av)
{
	int i;

	i = 0;
	int len = ac - 1;
	new_num *me = set_num_list(av);
	rank_list(len, av, &me);
	new_num *lst;
	lst = NULL;
	if (!is_sorted_list(me, len) && len > 5)
		big_sort(&me, &lst);
	else if (!is_sorted_list(me,len))
		five_sort(&me, &lst, len);
}
