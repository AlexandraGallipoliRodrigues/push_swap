/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:41:05 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/25 12:51:32 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char c)
{
	if (c < '0' || c > '9')
	{
		printf("ERROR\n");
		exit (0);
	}
}

static void	ft_int(long num, long val)
{
	if ((num * val) > 2147483647 || (num * val) < -2147483648)
	{
		printf("ERROR\n");
		exit (0);
	}
}

int	ft_atoi(const char *str)
{
	long	val;
	long	num;
	long	i;

	i = 0;
	num = 0;
	val = 1;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			val = -1;
		i++;
		ft_error(str[i]);
	}
	while (str[i])
	{
		ft_error(str[i]);
		num = num * 10 + (str[i++] - '0');
	}
	ft_int(num, val);
	return (num * val);
}
