/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:19:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/25 15:13:22 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_list **stack_a)
{
	int		max;
	t_list	*lst;

	max = (*stack_a)->content;
	lst = (*stack_a)->next;
	while (lst)
	{
		if (max < lst->content)
			max = lst->content;
		lst = lst->next;
	}
	return (max);
}

int	ft_low(t_list **stack_a)
{
	int		low;
	t_list	*lst;

	low = (*stack_a)->content;
	lst = (*stack_a)->next;
	while (lst)
	{
		if (low > lst->content)
			low = lst->content;
		lst = lst->next;
	}
	return (low);
}

void	ft_non_repeated(t_list	**stack_a)
{
	int		size;
	t_list	*temp;
	t_list	*stack;

	stack = *stack_a;
	size = ft_check_nums(stack_a);
	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (temp->content == stack->content)
			{
				printf("ERROR\n");
				exit (0);
			}
			temp = temp->next;
		}
		stack = stack->next;
		size--;
	}
}
