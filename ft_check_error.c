/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:19:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/24 13:32:53 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_isdigit(char c)
{
	if ((c >= 48 && c <= 57) || c == ' ')
		return (1);
	else
		return (0);
}
/*
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
}*/
void	ft_non_repeated(t_list	*stack_a)
{
	int	i;
	int	j;
	int	size;
	t_list	*temp;

	size = ft_check_nums(&stack_a);
	i = stack_a->content;
	while (size - 1 > 0)
	{
		temp = stack_a->next;
		j = temp->content;
		while (temp->next)
		{
			if (j == i)
			{
				printf("ERROR\n");
				exit (0);
			}
			temp = temp->next;
			j = temp->content;
		}
		stack_a = stack_a->next;
		i = stack_a->content;
		size--;
	}
}

/*int ft_check_error(t_list *stack_a)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = stack_a;
	while (temp)
	{
		i = ft_isdigit(temp->content);
		printf("%i\n", temp->content);
		if (i == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
	i = ft_not_repeated(stack_a);
	if (i == 0)
	{
		printf("ERROR\n");
		return (0);
	}
	else
		return (1);
}
*/
/*int ft_check_error(char **argv)
{
	int	i;
	int	j;
	int chk;

	i = 1;
	while (argv[i] != '\0')
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}*/

