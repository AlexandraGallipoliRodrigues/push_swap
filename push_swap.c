/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:12:08 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/25 15:14:55 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_swap(char **arguments, t_list **stack_a)
{
	int	i;
	int	tmp;

	i = 0;
	while (arguments[i] != '\0')
	{
		tmp = ft_atoi(arguments[i]);
		ft_lstadd_back(stack_a, ft_lstnew(tmp));
		i++;
	}
}

static int	ft_check_ord(t_list **stack_a)
{
	t_list	*prev;
	t_list	*lst;

	prev = *stack_a;
	lst = prev->next;
	while (lst)
	{
		if (prev->content > lst->content)
			return (1);
		prev = prev->next;
		lst = lst->next;
	}
	return (0);
}

static void	ft_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = ft_check_nums(stack_a);
	if (i == 3)
		ft_three(stack_a);
	else if (i > 3 && i <= 5)
		ft_five(stack_a, stack_b);
	else if (i <= 100)
		ft_big(stack_a, stack_b, 6);
	else if (i <= 500)
		ft_five_hundred(stack_a, stack_b, 15);
}

void leaks(void)
{
	system("leaks a.out");
}

int	main(int argc, char *argv[])
{
	char	**arguments;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	atexit(leaks);
	if (argc < 2)
		return (0);
	i = 1;
	while (argc > 1)
	{
		arguments = ft_split(argv[i], ' ');
		ft_push_swap(arguments, &stack_a);
		argc--;
		i++;
	}
	ft_non_repeated(&stack_a);
	if (ft_check_ord(&stack_a) == 0)
		return (0);
	else
		ft_algorithm(&stack_a, &stack_b);
	return (0);
}
