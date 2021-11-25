/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:53:08 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/25 12:56:11 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big(t_list **stack_a, t_list **stack_b, int chunk)
{
	t_chunk	chk;
	int		size;

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
