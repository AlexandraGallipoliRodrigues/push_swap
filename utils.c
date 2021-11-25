/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c  		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:28:31 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/25 12:20:04 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_while_ra(t_list **stack_a, int i)
{
	while (i > 0)
	{
		ft_ra(stack_a);
		i--;
	}
}

static void	ft_while_rra(t_list **stack_a, int i, int size)
{
	while (i < size)
	{
		ft_rra(stack_a);
		i++;
	}
}

void	ft_find_chk(t_list **stack_a, t_list **stack_b, int pos, t_chunk *chk)
{
	t_list	*temp;
	int		i;
	int		size;

	temp = *stack_a;
	i = 0;
	size = ft_check_nums(stack_a);
	while (ft_is_chunk(temp->content, chk->org, pos, chk->min) == 0)
	{
		i++;
		temp = temp->next;
	}
	if (i < (size / 2))
		ft_while_ra(stack_a, i);
	else
		ft_while_rra(stack_a, i, size);
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

int	ft_check_left(t_list **stack_a, int pos, t_chunk *chk)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->content >= chk->org[chk->min]
			&& temp->content < chk->org[pos])
			return (1);
		temp = temp->next;
	}
	return (0);
}
