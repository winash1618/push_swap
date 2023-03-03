#include "push_swap.h"

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
