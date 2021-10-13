/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:28:31 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/13 22:53:43 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_sort_int_tab(int	*org, int	size)
{
	int	x;
	int	y;
	int	temp;

	x = 0;
	while (x <= size - 1)
	{
		y = 0;
		while (y <= size - 2)
		{
			if (org[y] > org[x])
			{
				temp = org[x];
				org[x] = org[y];
				org[y] = temp;
			}
			y++;
		}
		x++;
	}
}

int	*ft_organised_array(t_list	*stack_a)
{
	int	i;
	int	*org;
	int	size;
	t_list	*temp;

	size = ft_check_nums(&stack_a);
	temp = stack_a;
	i = 0;
	while (i <= size && temp)
	{
		org[i] = temp->content;
		temp = temp->next;
		i++;
	}
	ft_sort_int_tab(org, size);
	i = 0;
	return (org);	
}

int	ft_median(t_list *stack_a)
{
	int	i;
	int	size;
	int median;
	t_list	*temp;

	i = 0;
	temp = stack_a;
	size = ft_check_nums(&stack_a);
	median = 0;
	while (i < size)
	{
		median += temp->content;
		temp = temp->next;
		i++;
	}
	median = median / size;
	return (median);
}

