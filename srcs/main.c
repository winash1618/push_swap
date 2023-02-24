#include "push_swap.h"

void init_level(t_stack *stack)
{
	while (stack)
	{
		stack->level = 0;
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	(void)stack_b;
	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	validate_args(argc, argv);
	init_stack(&stack_a, argc, argv);
	// str = ft_split(merge_args_with_spaces(argc, argv), ' ');
	// while (str[++i])
	// {
	// 	ft_dlstadd_back(&stack_a, ft_dlstnew(ft_atoi(str[i])));
	// 	printf("str[%d]: %s\n", i, str[i]);
	// }
	// 
	// sort_three(&stack_a);
	// sort_four(&stack_a, &stack_b);
	// sort_five_or_more_hard_way(&stack_a, &stack_b);
	init_level(stack_a);
	sort_divide_and_conquer(&stack_a, &stack_b, get_min);
	// ft_dlstprint(stack_a);
	// sa(&stack_a);
	// rra(&stack_a);
	// ra(&stack_a);
	// pb(&stack_a, &stack_b);
	// ft_dlstprint(stack_a);
	// ft_dlstprint(stack_b);
	// ft_dlstclear(&stack_a);
	// ft_dlstclear(&stack_b);
	// init_list(argc, argv);
	return (0);
}