/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:33:06 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/23 19:31:09 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_back_to_a(t_list **stack_a, t_list **stack_b, int chk)
{
	int	size;

	size = ft_check_nums(stack_b);
	while (size > 1)
	{
		ft_locate(stack_a, stack_b);
		size = ft_check_nums(stack_b);
	}
	ft_pa(stack_a, stack_b);
	return (1);
}

void	ft_loop(t_list **stack_a, t_list **stack_b, int pos,int *org, int min)
{
	while (1)
	{
		if (!ft_check_left(stack_a, org, pos, min))
			break;
		ft_find_chk_nums(stack_a, stack_b, org, pos, min);
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
	org = malloc(sizeof(int) * size);
	i = 0;
	while (temp)
	{
		org[i] = temp->content;
		temp = temp->next;
		i++;
	}
	ft_sort_int_tab(org, size); // Hasta aqui, funciona :)
	return (org);
}

void	ft_five_hundred(t_list **stack_a, t_list **stack_b, int chk)
{
	int		pos;
	int 	size;
	int		*org;
	int		temp;
	int		min;

	org = ft_organised_array(*stack_a);
	size = ft_check_nums(stack_a);
	min = 0;
	pos = (size/chk);
	temp = pos;
	while (chk > 0)
	{
		if (chk == 1)
			ft_loop(stack_a, stack_b, (pos - 1), org, min);
		else
			ft_loop(stack_a, stack_b, pos, org, min);
		min = pos;
		pos += temp;
		if (chk == 1)
			pos = size - 1;
		chk--;
	}
	ft_back_to_a(stack_a, stack_b, temp);
}
