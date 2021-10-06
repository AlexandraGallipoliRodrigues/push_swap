/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:41:54 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/06 11:41:56 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_ra(t_list **stack_a)
{
	t_list	*aux;

	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = NULL;
	ft_lstadd_back(stack_a, aux);
}

void ft_rb(t_list **stack_b)
{
	t_list	*aux;

	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = NULL;
	ft_lstadd_back(stack_b, aux);
}

void ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}
