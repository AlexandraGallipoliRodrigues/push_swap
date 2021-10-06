/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:41:05 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/06 11:42:27 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long	val;
	long	num;
	long	i;

	i = 0;
	num = 0;
	val = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			val = -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		num = num * 10 + (str[i++] - '0');
		if ((num * val) > 2147483647)
			return (-1);
		if ((num * val) < -2147483648)
			return (0);
	}
	return (num * val);
}
