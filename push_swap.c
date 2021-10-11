/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:12:08 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/08 20:38:03 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static t_list	*ft_push_swap(char **argv, t_list *stack_a)
{
	int	i;
	int	tmp;

	i = 0;
	while (argv[i] != '\0')
	{
		tmp = ft_atoi(argv[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(tmp));
		i++;
	}
	return (stack_a);
}

int	ft_check_nums(t_list **stack_a)
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
	t_list	*prev;
	t_list	*lst;

	prev = *stack_a;
	lst = prev->next;
	while (lst)
	{
		//printf("prev : %d\n", prev->content);
		//printf("lst : %d\n", lst->content);
		if (prev->content > lst->content)
			return (1);
		prev = prev->next;
		lst = lst->next;
	}
	return (0);
}

static void	ft_algorithm(int i, t_list **stack_a, t_list **stack_b)
{
	if (i == 3)
		ft_three(stack_a);
	else if (i > 3 && i <= 5)
		ft_five(stack_a, stack_b);
}

void	ft_print_lst(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;
	t_list	*aux2;

	aux = *stack_a;
	aux2 = *stack_b;
	while (aux)
	{
		printf("** %d **\n", aux->content);
		aux = aux->next;
	}
	printf("\n------\n");
	while (aux2)
	{
		printf("** %d **\n", aux2->content);
		aux2 = aux2->next;
	}
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
	if (argc <= 1)
		return(0);
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
	return (0);
}
