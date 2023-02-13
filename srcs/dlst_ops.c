#include "push_swap.h"

t_stack *ft_dlstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->rank = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_dlstadd_back(t_stack **olst, t_stack *nlst)
{
	t_stack *tmp;

	if (!olst || !nlst)
		return ;
	if (*olst == NULL)
	{
		*olst = nlst;
		return ;
	}
	tmp = *olst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nlst;
	nlst->prev = tmp;
}

void	ft_dlstadd_front(t_stack **olst, t_stack *nlst)
{
	if (!olst || !nlst)
		return ;
	if (*olst == NULL)
	{
		*olst = nlst;
		return ;
	}
	nlst->next = *olst;
	(*olst)->prev = nlst;
	*olst = nlst;
}

void	ft_dlstclear(t_stack **lst)
{
	t_stack *tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(tmp);
		tmp = *lst;
	}
}

t_stack	*ft_dlstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

