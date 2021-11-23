/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:41:54 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/23 13:42:43 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_ra(t_list **stack_a)
{
	t_list	*aux;

	if (!(*stack_a))
		return ;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = NULL;
	ft_lstadd_back(stack_a, aux);
	write(1, "ra\n", 3);
}

void ft_rb(t_list **stack_b)
{
	t_list	*aux;

	if (!(*stack_b))
		return ;
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = NULL;
	ft_lstadd_back(stack_b, aux);
	write(1, "rb\n", 3);
}

void ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	write(1, "rr\n", 3);
}
