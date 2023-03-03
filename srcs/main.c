#include "push_swap.h"

t_stack *duplicate_stack(t_stack *stack_a)
{
	t_stack *stack_c;
	t_stack *tmp;

	stack_c = NULL;
	tmp = stack_a;
	while (tmp)
	{
		t_stack *new = ft_dlstnew(tmp->content);
		new->rank = tmp->rank;
		new->level = tmp->level;
		ft_dlstadd_back(&stack_c, new);
		tmp = tmp->next;
	}
	return (stack_c);
}


int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_list *move_stack;

	(void)stack_b;
	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	move_stack = NULL;
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
	// t_stack *stack_c = duplicate_stack(stack_a);
	// ft_dlstprint(stack_c);
	sort_divide_and_conquer_a(&stack_a, &stack_b, get_min, &move_stack);
	optimize_moves(move_stack);
	// optimize_more_moves(move_stack, ft_dlstsize(stack_a));
	// make_moves(move_stack, &stack_c, &stack_b);
	// hard_optimizer(move_stack, stack_a, stack_c);
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
	// ft_dlstprint(stack_a);
	ft_lstprint(move_stack);
	return (0);
}