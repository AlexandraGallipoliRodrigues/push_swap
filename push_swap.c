/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:50:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/27 14:04:39 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(char **argv)
{
	t_list	*stack_a;
	t_list	*temp;
	int		i;

	stack_a = ft_lstnew(argv[0]);
	i = 1;
	printf("%s\n", stack_a->content);
	while (argv[i] != '\0')
	{
		temp = ft_lstnew(argv[i]);
		printf("%s\n", temp->content);
		ft_lstadd_back(&stack_a->next, temp);
		i++;
	}
}

/*char** ft_arguments(char **argv)
{
	int		i;
	char	**arguments;
	
	i = 0;
	while (argv[i] != '\0')
	{
		arguments = ft_split(argv[i], ' ');
		i++;
	}
	return (arguments);
}*/

int main (int argc, char *argv[])
{
	char	**arguments;
	int		i;
	char 	*chk;
	//arguments = (char **)malloc(sizeof(char*) * 200);

	i = 1;
	while (argc != 1)
	{
		chk = ft_strchr(argv[i], ' ');
		if (chk != NULL)
		{
			arguments = ft_split(argv[i], ' ');
			ft_push_swap(arguments);
		}
		else
			ft_push_swap(argv);
		argc--; 
		i++;
	}
	/*
	arguments = ft_split(argv[i], ' ');
	//arguments = ft_arguments(argv);
	ft_push_swap(arguments);*/
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
