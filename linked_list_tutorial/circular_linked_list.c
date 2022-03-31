/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:59:02 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/31 10:42:26 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct nums
{
    int data;
	int rank;
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
	//printf("* %d  ", lst->data);
	lst = lst->next_num;
	while (lst != num_first)
	{
		//printf("%d  ", lst->data);
		lst = lst->next_num;
		i++;
	}
	return (i);
}

void s_action(new_num **lst)
{
	write(1, "sa\n", 3);
	int i[4];
	i[0] = (*lst)->data;
	i[2] = (*lst)->rank;
	*lst = (*lst)->next_num;
	i[1] = (*lst)->data;
	i[3] = (*lst)->rank;
	(*lst)->data = i[0];
	(*lst)->rank = i[2];
	*lst = (*lst)->prev_num;
	(*lst)->data = i[1];
	(*lst)->rank = i[3];
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

// void radix_sort(new_num **l_a, new_num **l_b, int r, int len)
// {
// 	// for (int j = 1; j <= len; j++) 
// 	int k;
// 	int i;

// 	k = 0;
// 	i = 0;
// 	int j = 0;
// 	new_num *first_num = (*l_a);
// 	while ((*l_a) != NULL)
// 	{
// 		int temp = (*l_a)->data;
// 		temp /= r;
//         if (temp % 10 == i)
// 		{
// 			if (*l_a == first_num)
// 			{
// 				first_num = (*l_a)->next_num;
// 			}
//             p_action(l_a, l_b);
// 			//write (1, " pa rb ", 6);
//             r_action(l_b);
// 			j = j + 2;
//             k++;
// 			len--;
//         }
//         else
// 		{
//             	r_action(l_a);
// 				//write (1, " ra ", 6);
// 				j++;
//         }
// 		if (*l_a == first_num && i < 10  && temp % 10 != i)
// 		{
// 			i++;
// 		}
		
//     }printf("*** %d ***", j);
//     if (*l_b != NULL && !is_sorted_list(*l_b, k)) {
// 		len = k;
// 		r = r * 10;
//         radix_sort(l_b, l_a, r, len);
//     }
// }

void norm_sort(new_num **l_a, new_num **l_b, int len)
{
	int j = 0;
	while (*l_a != NULL)
	{
		if	(*l_b == NULL)
		{
			p_action(l_a, l_b, "pb");
			j++;
		}
		else if ((*l_a)->data <= (*l_b)->data)
		{
			while ((*l_a)->data < (*l_b)->prev_num->data && 
				*l_b != (*l_b)->prev_num && (*l_b)->data >= 
				(*l_b)->prev_num->data)
			{
				j++;
				rr_action(l_b, "rrb");
			}
			p_action(l_a, l_b, "pb");
		}
		else
		{
			while ((*l_a)->data > (*l_b)->next_num->data &&
			 *l_b != (*l_b)->next_num && (*l_b)->data <= 
			 (*l_b)->next_num->data)
			{
				j++;
				r_action(l_b, "rb");
			}
			j = j + 2;
			r_action(l_b, "rb");
			p_action(l_a, l_b, "pb");
		}
	}
	while (!is_sorted_list(*l_b, len))
	{
		j++;
		r_action(l_b, "rb");
	}
}

void	best_rotate(new_num **lst, int pos,	int do_a)
{
	int size;

	size = ft_lstsize(*lst);
	if (pos < size / 2)
	{
		while (pos > 0)
		{
			if (do_a)
				r_action(lst, "ra");
			else
				r_action(lst, "rb");
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			if (do_a)
				rr_action(lst, "rra");
			else
				rr_action(lst, "rrb");
			pos++;
		}
	}
}

int find_less(new_num *lst, int part)
{
	int	i;
	int	z;
	new_num *new;

	i = 0;
	new = lst;
	z = new->rank;
	while (new->next_num->rank != z)
	{
		if (new->rank <= part)
			break;
		++i;
		new = new->next_num;
	}
	return (i);
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

int	find_biggest(new_num *lst)
{
	int	i;
	int	largest;
	new_num	*new;

	new = lst;
	i = 0;
	largest = get_max(lst);
	while (1)
	{
		if (new->data == largest)
			break;
		++i;
		new = new->next_num;
	}
	return (i);
}

void	push_back_all(new_num **a, new_num **b, int i)
{
	int	pos;
	while (i > 0)
	{
		pos = find_biggest(*b);
		best_rotate(b, pos, 0);
		p_action(b, a, "pa");
		i--;
	}
}

void	big_sort(new_num **a, new_num **b)
{
	int	size;
	int	part;
	int	i;
	int	pos;
	
	size = ft_lstsize(*a);
	part = 0;
	i = 1;
	while (*a != NULL)
	{
		if (size <= 100)
			part += size / 5;
		else
			part += size / 11 - 2;
		while (i <= part)
		{
			if (*a == NULL)
				break;
			pos = find_less(*a, part);
			best_rotate(a, pos, 1);
			p_action(a, b, "pb");
			++i;
		}
	}
	push_back_all(a, b, i - 1);
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

void print_lst_with_rank(new_num *lst)
{
	new_num *lst2 = lst;
	printf("%d %d \n", lst->data, lst->rank);
	lst = lst->next_num;
	while (lst != lst2)
	{
		printf("%d %d \n", lst->data, lst->rank);
		lst = lst->next_num;
	}
}

void three_sort(new_num **l_a)
{
	if (((*l_a)->data < (*l_a)->next_num->data) && ((*l_a)->data < (*l_a)->next_num->next_num->data)
		&& ((*l_a)->next_num->data > (*l_a)->next_num->next_num->data))
	{
		s_action (l_a);
		r_action (l_a, "ra");
	}
	else if ((*l_a)->data > (*l_a)->next_num->data && ((*l_a)->data < (*l_a)->next_num->next_num->data)
		&& ((*l_a)->next_num->data < (*l_a)->next_num->next_num->data))
		s_action(l_a);
	else if ((*l_a)->data < (*l_a)->next_num->data && (*l_a)->data > (*l_a)->next_num->next_num->data
		&& ((*l_a)->next_num->data > (*l_a)->next_num->next_num->data))
		rr_action(l_a, "rra");
	else if ((*l_a)->data > (*l_a)->next_num->data && (*l_a)->data > (*l_a)->next_num->next_num->data)
	{	
		if ((*l_a)->next_num->data < (*l_a)->next_num->next_num->data)
			r_action(l_a, "ra");
		else
		{
			s_action(l_a);
			rr_action(l_a, "rra");
		}
	}
}

void four_sort(new_num **l_a, new_num **l_b, int len)
{
	int min = get_min(*l_a);

	if (len == 4)
	{
		if (min == (*l_a)->next_num->data)
			s_action(l_a);
		else if (min == (*l_a)->next_num->next_num->data)
		{
			r_action(l_a, "ra");
			s_action(l_a );
		}
		else if (min == (*l_a)->prev_num->data)
			rr_action(l_a, "rra");
		p_action(l_a, l_b, "pb");
	}
	three_sort(l_a);
}

void five_sort(new_num **l_a, new_num **l_b, int len)
{
	int min = get_min(*l_a);
	
	if (len == 5)
	{
		if (min == (*l_a)->next_num->data)
			s_action(l_a);
		else if (min == (*l_a)->next_num->next_num->data)
		{
			r_action(l_a, "ra");
			s_action(l_a);
		}
		else if (min == (*l_a)->prev_num->data)
			rr_action(l_a, "rra");
		else if (min == (*l_a)->prev_num->prev_num->data)
		{
			rr_action(l_a, "rra");
			rr_action(l_a, "rra");
		}
		p_action(l_a, l_b, "pb");
		len--;
	}
	four_sort(l_a, l_b, len);
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
	// printf ("%d %d %d\n", arr1[i], (*lst)->rank, (*lst)->data);
	(*lst)->rank = arr2[i];
	(*lst) = (*lst)->next_num;
	
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_string_number(char **av, int len)
{
	int i;
	int j;
	int k;

	i = 1;
	j = 0;
	k = 0;
	while (len--)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]))
			{
				if (!(av[i][j] == '-' && ft_isdigit(av[i][j + 1])))
				{
					k++;
				}
				else if (!((av[i][j] == '+') && ft_isdigit(av[i][j + 1])))
				{
					k++;
				}
			}
			j++;
			
		}
		i++;
	}
	if (k > 0)
		return (0);
	else
		return (1);
}

int is_duplicate(new_num *lst, int len)
{
	new_num *dup;
	size_t i;

	dup = lst;
	lst = lst->next_num;
	while (dup != lst)
	{
		i += lst->rank;
		lst = lst->next_num;
	}
	i++;
	if (i != len*(len-1)/2)
		return (1);
	return (0);
}

void quick_sort(new_num **l_a, new_num **l_b, int len)
{
	while (ft_lstsize(*l_a) != len / 2 && *l_a != NULL)
	{
		if ((*l_a)->data == get_min(*l_a))
			p_action(l_a, l_b, "pb");
		else
			r_action(l_a, "ra");
	}
	
	int temp = len;
	len = len/2;
	if (len > 2)
	{
		quick_sort(l_a, l_b, len);
		quick_sort(l_b, l_a, len);
	}
	if (*l_a != NULL)
		if ((*l_a)->rank > (*l_a)->next_num->rank)
			s_action(l_a);
	if (*l_b != NULL)
		if ((*l_b)->rank < (*l_b)->next_num->rank && *l_b != NULL)
			s_action(l_b);
	temp -= len;
	while (temp--)
	{
		p_action(l_b, l_a, "pa");
	}
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	int len = ac - 1;
	new_num *me = set_num_list(av);
	rank_list(len, av, &me);
	printf("%d", is_string_number(av, len));
	is_duplicate(me, len);
	//print_lst_with_rank(me);
	//print_lst(me);
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
	lst = NULL;
	//lst = ft_lstnew(ft_itoa(i));
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
	// radix_sort(&me, &lst, 1, len);
	// if (!is_sorted_list(me, len) && len > 5)
	// 	big_sort(&me, &lst);
	// else if (!is_sorted_list(me,len))
	// {
	// 	five_sort(&me, &lst, len);
	// 	while (lst != NULL)
	// 		p_action(&lst, &me, "pa");
	// }
	// print_lst(me);
	// if (!me)
	// 	me = lst;
	// lst = NULL;
	// i = 0;
	// while (me != NULL)
	// {
	// 	i = 0;
	// 	while (i < len)
	// 	{
	// 		if (arr2[i] == me->data)
	// 		{
	// 			me->data = arr1[i];
	// 			p_action(&me, &lst);
	// 			r_action(&lst);
	// 			if (me == NULL)
	// 				break;
	// 		}
	// 		i++;
	// 	}
	// }
	// if (!me)
	// 	print_lst(lst);
}
