/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:59:45 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/25 13:29:48 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fst_cond(t_list **stack_a)
{
	t_list	*prev;
	t_list	*lst;

	prev = *stack_a;
	lst = prev->next;
	if (prev->content > lst->content)
	{
		lst = lst->next;
		if (prev->content > lst->content)
		{
			prev = prev->next;
			if (prev->content > lst->content)
			{
				ft_sa(stack_a);
				ft_rra(stack_a);
			}
			else
				ft_ra(stack_a);
		}
		else
			ft_sa(stack_a);
	}
}

void	ft_three(t_list **stack_a)
{
	t_list	*prev;
	t_list	*lst;

	prev = *stack_a;
	lst = prev->next;
	if (prev->content > lst->content)
		ft_fst_cond(stack_a);
	else
	{
		lst = lst->next;
		if (prev->content > lst->content)
			ft_rra(stack_a);
		else
		{
			ft_sa(stack_a);
			ft_ra(stack_a);
		}
	}
}
