/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:28:31 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/26 13:43:36 by agallipo         ###   ########.fr       */
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
	printf("size = %i\n", size);
	org = malloc(sizeof(int) * size);
	i = 0;
	while (i < size && temp)
	{
		org[i] = temp->content;
		temp = temp->next;
		i++;
	}
	ft_sort_int_tab(org, size);
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

void	ft_big(t_list **stack_a, t_list **stack_b, int chk)
{
	int		pos;
	int 	size;
	int		*org;
	t_list	*temp;
	int		i;

	size = ft_check_nums(stack_a);
	pos = size/chk;
	org = ft_organised_array(*stack_a);
	printf("pos: %i\n org: %i\n", pos, org[pos]);
	temp = *stack_a;
	printf("hola\n");
	while (i <= 100)
	{
		printf("hola\n");
		if (temp->content <= org[pos])
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		temp = temp->next;

	}
	ft_print_lst(stack_a, stack_b);
}

