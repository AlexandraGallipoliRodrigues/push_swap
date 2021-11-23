/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c  		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:28:31 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/23 18:55:50 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int ft_is_chunk(int temp, int *org, int pos, int min)
{
	if (temp >= org[min] && temp < org[pos])
		return (1);
	return (0);
}

void	ft_find_chk_nums(t_list **stack_a, t_list **stack_b, int *org, int pos, int min)
{
	t_list	*temp;
	int		i;
	int		size;

	temp = *stack_a;
	i = 0;
	size = ft_check_nums(stack_a);
	while (ft_is_chunk(temp->content, org, pos, min) == 0)
	{
		i++;
		temp = temp->next;
	}
	if (i < (size / 2))
	{
		while (i > 0)
		{
			ft_ra(stack_a);
			i--;
		}
	}
	else
	{
		while (i < size)
		{
			ft_rra(stack_a);
			i++;
		}
	}
	ft_pb(stack_a, stack_b);
}

void	ft_sort_int_tab(int	*org, int	size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 1;
		while (j < size)
		{
			if (org[j] < org[j - 1])
			{
				temp = org[j];
				org[j] = org[j - 1];
				org[j - 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int ft_check_left(t_list **stack_a,int *org, int pos, int min)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->content >= org[min] && temp->content < org[pos])
			return (1);
		temp = temp->next;
	}
	return (0);
}
