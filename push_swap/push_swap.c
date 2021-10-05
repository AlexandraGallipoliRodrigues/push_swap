/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:50:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/05 12:59:30 by agallipo         ###   ########.fr       */
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
static	void ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = NULL;
	ft_lstadd_front(stack_b, aux);
}

static void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = NULL;
	ft_lstadd_front(stack_a, aux);
}

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
static void ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

static void ft_ra(t_list **stack_a)
{
	t_list	*aux;

	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = NULL;
	ft_lstadd_back(stack_a, aux);
}

static void ft_rb(t_list **stack_b)
{
	t_list	*aux;

	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = NULL;
	ft_lstadd_back(stack_b, aux);
}

static void ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

static void ft_rra(t_list **stack_a)
{
	t_list	*aux;
	t_list	*last;

	last = *stack_a;
	while (last->next)
		last = last->next;
	aux = ft_lstnew(last->content);
	aux->next = *stack_a;
	*stack_a = aux;
	free(last->content);
//	free(last);
//	last = 0;
//	last->content = 0;
/*	last->next = *stack_a;
	*stack_a = last;*/
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
	t_list	*stack_b;
	t_list	*aux2;
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
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	aux = stack_a;
	aux2 = stack_b;
	while(aux)
 	{
		printf("%s\n", aux->content);
		aux = aux->next;
	}
	printf("-------\n");
	while(aux2)
 	{
		printf("%s\n", aux2->content);
		aux2 = aux2->next;
	}
	ft_rra(&stack_a);
	aux = stack_a;
	aux2 = stack_b;
	printf("****************\n");
	while(aux)
 	{
		printf("%s\n", aux->content);
		aux = aux->next;
	}
	printf("-------\n");
	while(aux2)
 	{
		printf("%s\n", aux2->content);
		aux2 = aux2->next;
}

	printf("FIRST %s\n", stack_a->content);
	//system("leaks a.out");
	return (0);
}
