/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:41:13 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/27 11:17:33 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst)
	{
		i = 0;
		while (lst != NULL)
		{
			lst = lst->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}
