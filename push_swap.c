/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:50:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/28 13:22:53 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_push_swap(char **argv)
{
	t_list	*stack_a;
	t_list	*temp;
	int		i;

	stack_a = ft_lstnew(argv[0]);
	i = 1;
	//printf("%s\n", stack_a->content);
	while (argv[i] != '\0')
	{
		temp = ft_lstnew(argv[i]);
	//	printf("%s\n", temp->content);
		ft_lstadd_back(&stack_a, temp);
		i++;
	}
	return (stack_a);
}

int main (int argc, char *argv[])
{
	char	**arguments;
	t_list	*first;
	t_list	*temp;
	int		i;

	i = 1;
	while (argc != 1)
	{
		printf(" \n");
		arguments = ft_split(argv[i], ' ');
		temp = ft_push_swap(arguments);
		ft_lstadd_back(&first, temp);
		argc-- && i++;
	}
	printf("%p\n", &first);
	printf("FIRST%s\n", first->content);
	system("leaks a.out");
	return (0);
}

/*
int	main (int argc, char *argv[])
{
	char	*num[1000];
	int	i;
	int	j;

	i = 1;
	while (argv[i] != '\0')
	{
		num[i] = argv[i];
		printf("%s\n", num[i]);
		i++;
	}
	return (0);
}*/
