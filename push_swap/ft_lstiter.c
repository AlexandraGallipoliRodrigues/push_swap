/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:41:40 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/29 09:38:39 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*prev;

	if (!lst)
		return ;
	while (lst)
	{
		prev = lst;
		f(lst->content);
		lst = prev->next;
	}
}
