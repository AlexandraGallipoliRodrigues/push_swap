/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:41:37 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/23 13:42:52 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (!(*stack_a))
		return ;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = NULL;
	ft_lstadd_front(stack_b, aux);
	write(1,"pb\n", 3);
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (!(*stack_b))
		return ;
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = NULL;
	ft_lstadd_front(stack_a, aux);
	write(1, "pa\n", 3);
}
