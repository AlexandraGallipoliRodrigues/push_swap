#include "push_swap.h"

void	ft_print_lst(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;
	t_list	*aux2;
	int		i;

	aux = *stack_a;
	aux2 = *stack_b;
	while (aux)
	{
		printf("** %d **  ", aux->content);
		aux = aux->next;
		i = 0;
		while (i < 1 && aux2)
		{
			printf("** %d **", aux2->content);
			aux2 = aux2->next;
			i++;
		}
		printf("\n");
	}
}
