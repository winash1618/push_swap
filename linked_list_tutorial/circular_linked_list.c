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
int main(int ac, char **av)
{
	new_num *me = init_num_list(av);
	printf("%d", (me->next_num)->data);
}