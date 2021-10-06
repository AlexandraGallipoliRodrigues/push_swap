/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:41:37 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/06 11:41:39 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = NULL;
	ft_lstadd_front(stack_b, aux);
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = NULL;
	ft_lstadd_front(stack_a, aux);
}
