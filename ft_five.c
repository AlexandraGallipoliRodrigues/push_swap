/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:12:50 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/25 13:25:03 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_five_nums(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*lst;

	lst = *stack_a;
	i = 0;
	while (i < 2)
	{
		lst = *stack_a;
		if (lst->content == ft_low(stack_a))
		{
			ft_pb(stack_a, stack_b);
			break ;
		}
		ft_sa(stack_a);
		i++;
	}
}

static void	ft_four_nums(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst;

	while (ft_check_nums(stack_a) > 3)
	{
		lst = ft_lstlast(*stack_a);
		if (lst->content == ft_low(stack_a))
		{
			ft_rra(stack_a);
			ft_pb(stack_a, stack_b);
			break ;
		}
		ft_rra(stack_a);
	}
}

void	ft_five(t_list **stack_a, t_list **stack_b)
{
	while (ft_check_nums(stack_a) > 3)
	{
		ft_five_nums(stack_a, stack_b);
		ft_four_nums(stack_a, stack_b);
	}
	ft_three(stack_a);
	if (ft_check_nums(stack_b) == 2)
		ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
