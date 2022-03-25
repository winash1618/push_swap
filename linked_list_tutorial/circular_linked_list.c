# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct nums
{
    int data;
    struct nums *next_num;
    struct nums *prev_num;
} new_num;
size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
	{
		count++;
	}
	s = s - count;
	return (count);
}
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (*s1)
	{
		*ptr++ = *s1++;
		count++;
	}
	*ptr = '\0';
	ptr = ptr - count;
	s1 = s1 - count;
	return (ptr);
}


static int	num_len(int num)
{
	int	i;

	if (num < 0)
		i = 1;
	else
		i = 0;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int num)
{
	int			i;
	char		*s;
	int			len;
	long int	numb;

	numb = num;
	len = num_len(num);
	if (!num)
		return (ft_strdup ("0"));
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	i = len;
	s[i--] = '\0';
	if (numb < 0)
	{
		s[0] = '-';
		numb = -numb;
	}
	while (numb)
	{
		s[i--] = numb % 10 + '0';
		numb /= 10;
	}
	return (s);
}

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
	new->prev_num = (*lst)->prev_num;
	(*lst)->prev_num->next_num = new;
	(*lst)->prev_num = new;
	new->next_num = (*lst);
	
}
void ft_lstadd_back(new_num **lst, new_num *new)
{
	new->next_num = (*lst);
	new->prev_num = (*lst)->prev_num;
	(*lst)->prev_num->next_num = new;
	(*lst)->prev_num = new;
}
int ft_lstsize(new_num *lst)
{
	int i = 1; // sart with zero
	new_num *num_first = lst;
	if (lst == NULL)
		return (0);
	printf("* %d  ", lst->data);
	lst = lst->next_num;
	while (lst != num_first)
	{
		printf("%d  ", lst->data);
		lst = lst->next_num;
		i++;
	}
	return (i);
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

void delete_num(new_num **lst)
{
	if (*lst == (*lst)->next_num)
		*lst = NULL;
	else
	{
		((*lst)->prev_num)->next_num = (*lst)->next_num;
		((*lst)->next_num)->prev_num = (*lst)->prev_num;
		(*lst) = (*lst)->next_num;
	}
}
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
void p_action(new_num **src, new_num **dst)
{
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


void r_action(new_num **lst)
{
	(*lst) = (*lst)->next_num;
}

void rr_action(new_num **lst)
{
	(*lst) = (*lst)->prev_num;
}

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
void radix_sort(new_num **l_a, new_num **l_b, int r, int len)
{
	// for (int j = 1; j <= len; j++) 
	int k;
	int i;
	int j;

	k = 0;
	i = 0;
	j = -1;
	new_num *first_num = (*l_a);
	while ((*l_a) != NULL)
	{
		int temp = (*l_a)->data;
		temp /= r;
        if (temp % 10 == i)
		{
			if (*l_a == first_num)
			{
				first_num = (*l_a)->next_num;
			}
            p_action(l_a, l_b);
            r_action(l_b);
            k++;
			len--;
        }
		else if (temp % 10 == j)
		{
			if (*l_a == first_num)
			{
				first_num = (*l_a)->next_num;
			}
            p_action(l_a, l_b);
            k++;
			len--;
		}
        else
		{
            	r_action(l_a);
        }
		if (*l_a == first_num && i < 10  && temp % 10 != i && (*l_a)->data >= 0 )
		{
			i++;
		}
		else if (*l_a == first_num && j > -10 && temp % 10 != j)
		{
			j--;
		}
    }
    if (*l_b != NULL && !is_sorted_list(*l_b, k)) {
		len = k;
		r = r * 10;
        radix_sort(l_b, l_a, r, len);
    }
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
void print_lst(new_num *lst)
{
	new_num *lst2 = lst;
	printf("%d ", lst->data);
	lst = lst->next_num;
	while (lst != lst2)
	{
		printf("%d ", lst->data);
		lst = lst->next_num;
	}
}
int main(int ac, char **av)
{
	int i;

	i = 0;
	int len = ac - 1;
	new_num *me = set_num_list(av);
	// printf("%d", (me->next_num)->data);
	// s_action(&me);
	// //printf("%d", (me->next_num)->data);
	// //printf("%d", ft_lstsize(me));
	// //printf("%d \n", ft_lstsize(me));
	// while (i<5)
	// {
	// 	//ft_lstadd_front(&me, ft_lstnew(ft_itoa(i)));
	// 	ft_lstadd_back(&me, ft_lstnew(ft_itoa(i)));
	// 	i++;
	// }
	// //printf("%d", ft_lstsize(me));
	new_num *lst;
	// lst = ft_lstnew(ft_itoa(i));
	// // printf("%d", ft_lstsize(lst));
	// // printf("%d", me->data);
	// printf(" \n* %d", ft_lstsize(me));
	// p_action(&me, &lst);
	// p_action(&me, &lst);
	// print_lst(me);
	// int max = get_min (me);
	// printf("%d", max);
	// int j = 1;
	// while (max > 0)
	// {
	// 	max /= 10;
	// 	radix_sort(&me, &lst, j, len);
	// 	j = j * 10;
	// }
	// print_lst(me);
	radix_sort(&me, &lst, 1, len);
	if (!me)
		print_lst(lst);
	else 
		print_lst(me);
	printf("%d", -3 % 2);
	//printf("%d", is_sorted_list(me, len));
	//p_action(&lst, &me);
	// printf(" \n* %d", ft_lstsize(me));
	// radix_sort(&me);
	//radix_sort(&me, 1);
	// printf("%d", ft_lstsize(me));
	 // printf("%d", me->data);
	// ft_lstadd_front(&ne, ne1);
	// printf("%d", (ne->next_num)->data);
}
