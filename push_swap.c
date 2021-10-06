/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:50:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/06 13:09:50 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static t_list	*ft_push_swap(char **argv, t_list *stack_a)
{
	int		i;
	int  *tmp ;


	i = 0;
	while (argv[i] != '\0')
	{
		tmp = malloc(sizeof(int));
		*tmp = ft_atoi(argv[i]);
		ft_lstadd_back(&stack_a,ft_lstnew(tmp));
		i++;
	}
	return (stack_a);
}


int main (int argc, char *argv[])
{
	char	**arguments;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*aux2;
	t_list	*aux;
	int		i;

	i = 1;
	// stack_a = ft_lstnew(argv[1]);
	while (argc > 1)
	{
		arguments = ft_split(argv[i], ' ');
		stack_a = ft_push_swap(arguments, stack_a);
		argc-- && i++;
	}
	// ft_convert(&stack_a);

	aux = stack_a;
	aux2 = stack_b;
	while(aux)
 	{

		printf("** %d **\n", *((int *)aux->content));
		aux = aux->next;
	}

	return (0);
}
