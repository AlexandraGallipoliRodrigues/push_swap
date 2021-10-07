
#include "push_swap.h"

void	ft_three(t_list **stack_a)
{
	int		j;
	int		a;
	int		b;
	t_list	*prev;
	t_list	*lst;

	prev = *stack_a;
	lst = prev->next;
	a = (*((int *)prev->content));
	b = (*((int *)lst->content));
	if (b < a)
	{
		prev = prev->next;
		lst = prev->next;
		a = (*((int *)prev->content));
		b = (*((int *)lst->content));
		if (b < a)
		{
			prev = *stack_a;
			a = (*((int *)prev->content));
			if (b < a)
				ft_ra(stack_a);
			else
				ft_sa(stack_a);
		}
		else
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
	}
	else
	{
		lst = prev->next;
		b = (*((int *)lst->content));
		if (b < a)
		{
			ft_sa(stack_a);
			ft_ra(stack_a);
		}
		else
			ft_rra(stack_a);
	}
}
