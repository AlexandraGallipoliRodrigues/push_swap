/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:33:06 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/25 12:55:38 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_back_to_a( t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_check_nums(stack_b);
	while (size > 1)
	{
		ft_locate(stack_a, stack_b);
		size = ft_check_nums(stack_b);
	}
	ft_pa(stack_a, stack_b);
}

void	ft_loop(t_list **stack_a, t_list **stack_b, int pos, t_chunk *chk)
{
	while (1)
	{
		if (!ft_check_left(stack_a, pos, chk))
			break ;
		ft_find_chk(stack_a, stack_b, pos, chk);
	}
}

int	*ft_organised_array(t_list	*stack_a)
{
	int		i;
	int		*org;
	int		size;
	t_list	*temp;

	size = ft_check_nums(&stack_a);
	temp = stack_a;
	org = malloc(sizeof(int) * size);
	i = 0;
	while (temp)
	{
		org[i] = temp->content;
		temp = temp->next;
		i++;
	}
	ft_sort_int_tab(org, size);
	return (org);
}

void	ft_five_hundred(t_list **stack_a, t_list **stack_b, int chunk)
{
	int		size;
	t_chunk	chk;

	chk.org = ft_organised_array(*stack_a);
	size = ft_check_nums(stack_a);
	chk.min = 0;
	chk.pos = (size / chunk);
	chk.temp = chk.pos;
	while (chunk > 0)
	{
		if (chunk == 1)
			ft_loop(stack_a, stack_b, (chk.pos - 1), &chk);
		else
			ft_loop(stack_a, stack_b, chk.pos, &chk);
		chk.min = chk.pos;
		chk.pos += chk.temp;
		if (chunk == 1)
			chk.pos = size - 1;
		chunk--;
	}
	ft_back_to_a(stack_a, stack_b);
}
