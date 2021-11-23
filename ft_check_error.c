/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:19:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/23 21:12:51 by agallipo         ###   ########.fr       */
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
}*//*
static int	ft_non_repeated(char	**argv)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (argv[i] != '\0')
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			n = 1;
			while (argv[i][n] != '\0')
			{
				if
			}


		}
	}
}*/

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
int ft_check_error(char **argv)
{
	int	i;
	int	j;
	int chk;

	i = 1;
	while (argv[i] != '\0')
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			return (0);
		else
		{
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
}

