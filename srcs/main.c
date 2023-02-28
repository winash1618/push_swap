#include "push_swap.h"

void init_level(t_stack *stack)
{
	while (stack)
	{
		stack->level = 0;
		stack = stack->next;
	}
}

void ft_lstprint(t_list *move_stack)
{
	while (move_stack)
	{
		printf("%s\n", (char *)move_stack->content);
		move_stack = move_stack->next;
	}
}

void optimize_moves(t_list *moves)
{
	t_list *head;
	t_list *old;

	old = NULL;
	head = moves;
	while (moves->next)
	{
		if (!ft_strncmp(moves->content, "rra", 3) && !ft_strncmp(moves->next->content, "ra", 2))
		{
			old->next = moves->next->next;
			moves = head;
		}	
		old = moves;
		moves = moves->next;
	}
	moves = head;
	while (moves->next)
	{
		if (!ft_strncmp(moves->content, "ra", 2) && !ft_strncmp(moves->next->content, "rra", 3))
		{
			old->next = moves->next->next;
			moves = head;
		}	
		old = moves;
		moves = moves->next;
	}
	moves = head;
	while (moves->next)
	{
		if (!ft_strncmp(moves->content, "pa", 2) && !ft_strncmp(moves->next->content, "pb", 2))
		{
			old->next = moves->next->next;
			moves = head;
		}	
		old = moves;
		moves = moves->next;
	}
	moves = head;
	while (moves->next)
	{
		if (!ft_strncmp(moves->content, "pb", 2) && !ft_strncmp(moves->next->content, "pa", 2))
		{
			old->next = moves->next->next;
			moves = head;
		}	
		old = moves;
		moves = moves->next;
	}
	moves = head;
	while (moves->next)
	{
		if (!ft_strncmp(moves->content, "rb", 2) && !ft_strncmp(moves->next->content, "rrb", 3))
		{
			old->next = moves->next->next;
			moves = head;
		}	
		old = moves;
		moves = moves->next;
	}
	moves = head;
	while (moves->next)
	{
		if (!ft_strncmp(moves->content, "rrb", 2) && !ft_strncmp(moves->next->content, "rb", 2))
		{
			old->next = moves->next->next;
			moves = head;
		}	
		old = moves;
		moves = moves->next;
	}
}


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

void make_moves(t_list *stack, t_stack **temp, t_stack **temp2)
{
	t_stack **a;
	t_stack **b;

	a = temp;
	b = temp2;
	ft_dlstprint(*a);
	ft_dlstprint(*b);
	while (stack)
	{
		if (ft_strncmp(stack->content, "ra", 2) == 0)
		{
			rotate(a);
			printf("ra\n");
		}
		else if (ft_strncmp(stack->content, "rb", 2) == 0)
		{
			rotate(b);
			printf("rb\n");
		}
		else if (ft_strncmp(stack->content, "rra", 3) == 0)
		{
			reverse_rotate(a);
			printf("rra\n");
		}
		else if (ft_strncmp(stack->content, "rrb", 3) == 0)
		{
			reverse_rotate(b);
			printf("rrb\n");
		}
		else if (ft_strncmp(stack->content, "pb", 2) == 0)
		{
			push(a, b);
			printf("pb\n");
		}
		else if (ft_strncmp(stack->content, "pa", 2) == 0)
		{
			push(b, a);
			printf("pa\n");
		}
		else if (ft_strncmp(stack->content, "sb", 2) == 0)
		{
			swap(b);
			printf("sb\n");
		}
		else if (ft_strncmp(stack->content, "sa", 2) == 0)
		{
			swap(a);
			printf("sa\n");
		}
		ft_dlstprint(*a);
		ft_dlstprint(*b);
		stack = stack->next;
	}
}

void optimize_more_moves(t_list *moves, int counter)
{
	t_list *head;
	t_list *old;

	head = moves;
	old = moves;
	int rra_counter = 0;
	int rrb_counter = 0;
	int size = counter;
	while (moves)
	{
		if (!ft_strncmp(moves->content, "pa", 2))
		{
			counter++;
		}
		else if (!ft_strncmp(moves->content, "pb", 2))
		{
			counter--;
		}
		else if (!ft_strncmp(moves->content, "rra", 3))
		{
			rra_counter = 0;
			while (moves->next)
			{
				if (!ft_strncmp(moves->content, "rra", 3))
				{
					rra_counter++;
				}
				else
					break ;
				moves = moves->next;
			}
			if (rra_counter == counter)
			{
				old->next = moves;
				moves = old->next;
			}
			if (!ft_strncmp(moves->content, "pa", 2))
			{
				counter++;
			}
			else if (!ft_strncmp(moves->content, "pb", 2))
			{
				counter--;
			}
			
		}
		else if (!ft_strncmp(moves->content, "rrb", 3))
		{
			rrb_counter = 0;
			while (moves->next)
			{
				if (!ft_strncmp(moves->content, "rrb", 3))
				{
					rrb_counter++;
				}
				else
					break ;
				moves = moves->next;
			}
			if (rrb_counter == size - counter)
			{
				old->next = moves;
				moves = old->next;
			}
			if (!ft_strncmp(moves->content, "pa", 2))
			{
				counter++;
			}
			else if (!ft_strncmp(moves->content, "pb", 2))
			{
				counter--;
			}
		}
		else if (!ft_strncmp(moves->content, "ra", 2))
		{
			rra_counter = 0;
			while (moves->next)
			{
				if (!ft_strncmp(moves->content, "ra", 2))
				{
					rra_counter++;
				}
				else
					break ;
				moves = moves->next;
			}
			if (rra_counter == counter)
			{
				old->next = moves;
				moves = old->next;
			}
			if (!ft_strncmp(moves->content, "pa", 2))
			{
				counter++;
			}
			else if (!ft_strncmp(moves->content, "pb", 2))
			{
				counter--;
			}
			
		}
		else if (!ft_strncmp(moves->content, "rb", 3))
		{
			rrb_counter = 0;
			while (moves->next)
			{
				if (!ft_strncmp(moves->content, "rb", 3))
				{
					rrb_counter++;
				}
				else
					break ;
				moves = moves->next;
			}
			if (rrb_counter == size - counter)
			{
				old->next = moves;
				moves = old->next;
			}
			if (!ft_strncmp(moves->content, "pa", 2))
			{
				counter++;
			}
			else if (!ft_strncmp(moves->content, "pb", 2))
			{
				counter--;
			}
		}
		old = moves;
		moves = moves->next;
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
	optimize_more_moves(move_stack, ft_dlstsize(stack_a));
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