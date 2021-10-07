/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancarlospopapopa <juancarlospopapopa@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:50:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/07 13:19:26 by juancarlosp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_push_swap(char **argv, t_list *stack_a)
{
	int	i;
	int	*tmp ;

	i = 0;
	while (argv[i] != '\0')
	{
		tmp = malloc(sizeof(int));
		*tmp = ft_atoi(argv[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(tmp));
		i++;
	}
	return (stack_a);
}

static int	ft_check_nums(t_list **stack_a)
{
	int		i;
	t_list	*lst;

	i = 0;
	lst = *stack_a;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

static int	ft_check_ord(t_list **stack_a)
{
	int		j;
	int		a;
	int		b;
	t_list	*prev;
	t_list	*lst;

	j = 0;
	prev = *stack_a;
	lst = *stack_a;
	lst = lst->next;
	a = (*((int *)prev->content));
	b = (*((int *)lst->content));
	while (a < b && lst->next)
	{
		a = (*((int *)prev->content));
		b = (*((int *)lst->content));
		prev = prev->next;
		lst = lst->next;
		j++;
	}
	printf("num j: %d\n", j);
	if (j == ft_check_nums(stack_a))
		return (0);
	return (1);
}

static void	ft_algorithm(int i, t_list **stack_a, t_list **stack_b)
{
	if (i == 3)
		ft_three(stack_a);
}

int	main (int argc, char *argv[])
{
	char	**arguments;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*aux2;
	t_list	*aux;
	int		i;

	i = 1;
	while (argc > 1)
	{
		arguments = ft_split(argv[i], ' ');
		stack_a = ft_push_swap(arguments, stack_a);
		argc-- && i++;
	}
	 i = ft_check_nums(&stack_a);
	 printf("num: %d\n", i);
	if (ft_check_ord(&stack_a) == 0)
		return (0);
	else
		ft_algorithm(i, &stack_a, &stack_b);
	aux = stack_a;
	aux2 = stack_b;
	while (aux)
	{
		printf("** %d **\n", *((int *)aux->content));
		aux = aux->next;
	}
	printf("\n------\n");
	while (aux2)
	{
		printf("** %d **\n", *((int *)aux2->content));
		aux2 = aux2->next;
	}
	/*printf("\n\n++++++++++++++++++++\n\n");
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	//ft_ss(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	aux = stack_a;
	aux2 = stack_b;
	while (aux)
	{
		printf("** %d **\n", *((int *)aux->content));
		aux = aux->next;
	}
	printf("\n------\n");
	while (aux2)
	{
		printf("** %d **\n", *((int *)aux2->content));
		aux2 = aux2->next;
	}*/
	return (0);
}
