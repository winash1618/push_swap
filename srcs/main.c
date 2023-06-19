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


void sorting_logic(t_stack **s_a, t_stack **s_b, t_list **moves)
{
	init_level(*s_a);
	if (ft_dlstsize(*s_a) == 3)
		sort_three(s_a, moves);
	else if (ft_dlstsize(*s_a) == 4)
		sort_four(s_a, s_b, moves);
	else if (ft_dlstsize(*s_a) >= 5 && ft_dlstsize(*s_b) <= 40)
		sort_five_or_more_hard_way(s_a, s_b, moves);
	else
	{
		sort_divide_and_conquer_a(s_a, s_b, get_min, moves);
		optimize_moves(*moves);
	}
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
	sorting_logic(&stack_a, &stack_b, &move_stack);
	ft_dlstclear(&stack_a);
	ft_dlstclear(&stack_b);
	ft_lstprint(move_stack);
	return (0);
}