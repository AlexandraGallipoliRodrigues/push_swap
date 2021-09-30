/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:50:42 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/30 12:40:32 by agallipo         ###   ########.fr       */
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
static void ft_sa(t_list *first)
{
	t_list	*second;
	t_list	*aux;
	

	second = first->next;
	aux = second;
	second->content = first->content;
	first->content = aux->content;
	printf("holaiaaa\n");
}
static t_list	*ft_push_swap(char **argv, t_list *first)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (argv[i] != '\0')
	{
		temp = ft_lstnew(argv[i]);
		ft_lstadd_back(&first, temp);
		i++;
	}
	return (first);
}

int main (int argc, char *argv[])
{
	char	**arguments;
	t_list	*first;
	t_list	*temp;
	t_list	*aux;
	int		i;

	i = 2;
	first = ft_lstnew(argv[1]);
	while (argc > 2)
	{
		arguments = ft_split(argv[i], ' ');
		temp = ft_push_swap(arguments, first);
		argc-- && i++;
	}
	ft_sa(first);
	aux = first;
	while(aux)
	{
		printf("%s\n", aux->content);
		aux = aux->next;
	}

	printf("FIRST%s\n", first->content);
	system("leaks a.out");
	return (0);
}
