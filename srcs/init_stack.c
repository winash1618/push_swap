#include "push_swap.h"

char *ft_strjoin_with_spaces(char const *s1, char const *s2)
{
	char	*str;
	int		count1;
	int		count2;

	if (!s1 || !s2)
		return (NULL);
	count1 = ft_strlen(s1);
	count2 = ft_strlen(s2);
	str = (char *) ft_calloc((count1 + count2 + 2), sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, count1);
	ft_memcpy(str + count1, " ", 1);
	ft_memcpy(str + count1 + 1, s2, count2);
	return (str);
}

char *merge_args_with_spaces(int argc, char **argv)
{
	int i;
	char *merged_arg;
	char *temp;

	i = 0;
	merged_arg = "";
	temp = NULL;
	while(++i < argc)
	{
		merged_arg = ft_strjoin_with_spaces(merged_arg, argv[i]);
		if (temp)
			free(temp);
		temp = merged_arg;
	}
	printf("merged string: %s\n", merged_arg);
	return (merged_arg);
}

void add_ranks_to_each_nodes(t_stack *stack)
{
	t_stack *temp1;
	t_stack *temp2;

	temp1 = stack;
	while (temp1)
	{
		temp2 = stack;
		while (temp2)
		{
			if (temp1->content > temp2->content)
				temp1->rank += 1;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void check_stack_for_duplicates(t_stack **stack)
{
	int size;
	int sum;

	size = ft_dlstsize(*stack);
	sum = size * (size - 1) / 2;
	if (sum != ft_dlstrank_sum(*stack))
		error_stack_exit(stack);
}

void init_stack(t_stack **stack, int argc, char **argv)
{
	int i;
	char **str;

	str = split_then_free(merge_args_with_spaces(argc, argv), ft_split);
	check_range_error(str);
	i = -1;
	while (str[++i])
	{
		ft_dlstadd_back(stack, ft_dlstnew(ft_atoi_modified(str[i], str)));
		free(str[i]);
	}
	free(str);
	add_ranks_to_each_nodes(*stack);
	check_stack_for_duplicates(stack);
}