/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:19:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/13 22:53:37 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static	int	ft_not_repeated(t_list	*stack_a)
{
	int	x;
	int	y;
	int	size;
	int	*temp;

	temp = ft_organised_array(stack_a);
	size = ft_check_nums(&stack_a);
	x = 0;
	while (x <= size - 1)
	{
		y = 0;
		while (y <= size - 2)
		{
			if (temp[y] == temp[x])
				return(0);
			y++;
		}
		x++;
	}
	return (1);
}

int ft_check_error(t_list *stack_a)
{
	int		i;
	t_list	*temp;

	temp = stack_a;
	while (temp)
	{
		i = ft_isdigit(temp->content);
		if (i == 0)
			return (0);
		temp = temp->next;
	}
	i = ft_not_repeated(stack_a);
	if (i == 0)
	{
		printf("ERROR\n");
		return (0);
	}
	else
		return (1);
}

