/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:37:34 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/25 13:41:49 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_nums(t_list **stack_a)
{
	int		i;
	t_list	*lst;

	i = 0;
	lst = *stack_a;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_locate(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		i;
	int		size;

	i = 0;
	temp = *stack_b;
	size = ft_check_nums(stack_b);
	while (temp->content != ft_max(stack_b))
	{
		temp = temp->next;
		i++;
	}
	if (i < (size / 2))
	{
		while ((*stack_b)->content != ft_max(stack_b))
			ft_rb(stack_b);
		ft_pa(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->content != ft_max(stack_b))
			ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
	}
}

int	ft_is_chunk(int temp, int *org, int pos, int min)
{
	if (temp >= org[min] && temp < org[pos])
		return (1);
	return (0);
}
