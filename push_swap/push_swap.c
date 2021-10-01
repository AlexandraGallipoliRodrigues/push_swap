/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:50:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/01 12:51:56 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void free_list(t_list *list)
{
   t_list	*tmp;

   while (list)
    {
       tmp = list;
       list = list->next;
       free(tmp);
    }

}*/
static void ft_sa(t_list **stack_a)
{
	t_list	*aux;
	
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = (*stack_a)->next;
	(*stack_a)->next = aux;
}

static void ft_sb(t_list **stack_b)
{
	t_list	*aux;
	
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = (*stack_b)->next;
	(*stack_b)->next = aux;
}

static t_list	*ft_push_swap(char **argv, t_list *stack_a)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (argv[i] != '\0')
	{
		temp = ft_lstnew(argv[i]);
		ft_lstadd_back(&stack_a, temp);
		i++;
	}
	return (stack_a);
}

int main (int argc, char *argv[])
{
	char	**arguments;
	t_list	*stack_a;
	t_list	*aux;
	int		i;

	i = 2;
	stack_a = ft_lstnew(argv[1]);
	while (argc > 2)
	{
		arguments = ft_split(argv[i], ' ');
		stack_a = ft_push_swap(arguments, stack_a);
		argc-- && i++;
	}
	ft_sa(&stack_a);
	aux = stack_a;
	while(aux)
	{
		printf("%s\n", aux->content);
		aux = aux->next;
	}

	printf("FIRST%s\n", stack_a->content);
	//system("leaks a.out");
	return (0);
}
