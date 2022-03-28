#include "push_swap.h"

void s_action(new_num **lst)
{
	write(1, "sa\n", 3);
	int temp1;
	int temp2;
	temp1 = (*lst)->data;
	*lst = (*lst)->next_num;
	temp2 = (*lst)->data;
	(*lst)->data = temp1;
	*lst = (*lst)->prev_num;
	(*lst)->data = temp2;
}

void p_action(new_num **src, new_num **dst, char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
    new_num *save;
    new_num *stock;

    if (*src == NULL)
        return;
    save = *src;
    delete_cond(src);
    if ((*dst) != NULL) {
        stock = (*dst)->prev_num;
        (*dst)->prev_num = save;
        (*dst)->prev_num->next_num = (*dst);
        (*dst)->prev_num->prev_num = stock;
        (*dst)->prev_num->prev_num->next_num = save;
        *dst = (*dst)->prev_num;
    }
    else {
        (*dst) = save;
        (*dst)->next_num = (*dst);
        (*dst)->prev_num = (*dst);
    }
}

void r_action(new_num **lst, char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	(*lst) = (*lst)->next_num;
}

void rr_action(new_num **lst, char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	(*lst) = (*lst)->prev_num;
}