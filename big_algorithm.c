/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:28:31 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/28 14:14:59 by agallipo         ###   ########.fr       */
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

static void	ft_loop(t_list **stack_a, t_list **stack_b, int pos,int *org)
{
	t_list	*temp;
	int		i;

	i = ft_check_nums(stack_a);
	temp = *stack_a;
	printf("ORG[POS] : %i\n", org[pos]);
	while (i >= 0 && temp)	{
		if (temp->content <= org[pos])
		{
			temp= temp->next;
			ft_pb(stack_a, stack_b);
		}
		else
		{
			temp = temp->next;
			ft_ra(stack_a);
		}
		i--;
	}
}

void	ft_big(t_list **stack_a, t_list **stack_b, int chk)
{
	int		pos;
	int 	size;
	int		*org;

	org = ft_organised_array(*stack_a);
	size = ft_check_nums(stack_a);
	pos = size/chk;
	while (chk > 0)
	{
		printf("POSICION: %i\nSIZE: %i\n", pos, size);
		ft_loop(stack_a, stack_b, pos, org);
		pos += pos;
		if (pos > size)
		{
			printf("HOLA\n");
			pos = size - 1;	
		}
		chk--;
	}
	ft_print_lst(stack_a, stack_b);
}
