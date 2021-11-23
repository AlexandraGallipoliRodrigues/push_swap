/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:28:31 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/23 18:24:54 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int ft_sort_chunk(t_list **stack_a, t_list **stack_b, int pos)
{
	int		i;
	int		count;

	count = 0;
	while (pos > 0 && *stack_b)
	{
		if (*stack_b && (*stack_b)->content == ft_max(stack_b))
		{
			ft_pa(stack_a, stack_b);
			pos--;
		}
		else
		{
			ft_rb(stack_b);
			count++;
		}
	}
	return(count);
}

static void	ft_back_to_a(t_list **stack_a, t_list **stack_b, int chk)
{
	int		pos;
	int		size;
	int		org;
	int		count;

	size = ft_check_nums(stack_b);
	pos = size/chk;
	while (chk > 0)
	{
		org = size/chk;
		while (org >= 0)
		{
			count = ft_sort_chunk(stack_a, stack_b, pos);
			pos = count;
			while (count > 0)
			{
				ft_rrb(stack_b);
				count--;
			}
			printf("SIZE: %i\nCOUNT: %i\nPOS: %i\nCHK: %i\n", size, count, pos, chk);
			org--;
		}
		chk--;
	}
}*/
/*static t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}*/
static void ft_pass(t_list **stack_a, int pos, int *org)
{
	while ((*stack_a)->content < org[pos - 1])
		ft_ra(stack_a);
	ft_ra(stack_a);
}
static int	ft_compare(int size, int i)
{
	if (i > size / 2)
		return (size - i);
	return (i);
}
static void	ft_locate(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		i;
	int		j;
	int		size;

	i = 0;
	//j = 0;
	temp = *stack_b;
	size = ft_check_nums(stack_b);
	while (temp->content != ft_max(stack_b))
	{
		temp = temp->next;
		i++;
	}
	//temp = *stack_b;
	/*while (temp->content != ft_low(stack_b))
	{
		temp = temp->next;
		j++;
	}*/
	//i = ft_compare(size, i);
	//j = ft_compare(size, j);
	//if (i < j)
	//{
	if (i < (size / 2))
	{
		while ((*stack_b)->content != ft_max(stack_b))
			ft_rb(stack_b);
		ft_pa(stack_a, stack_b);
	}

		/*else
			return (2);*/
	// }
	else
	{
		while ((*stack_b)->content != ft_max(stack_b))
			ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
		/*if (j < (size / 2))
			return (1);*/
		//else
		//return (3);
	}
	/*if ((i < (size / 2)) && i < j)
		return (0);
	else if ((j < (size / 2)) && j < i)
		return (1);
	else if ((i > (size / 2)) && i > j)
		return (2);
	return (3);*/
}

static int ft_is_chunk(int temp, int *org, int pos, int min)
{
	if (temp >= org[min] && temp < org[pos])
		return (1);
	return (0);
}
static void ft_find_chk_nums(t_list **stack_a, t_list **stack_b, int *org, int pos, int min)
{
	t_list	*temp;
	int		i;
	int		size;

	temp = *stack_a;
	i = 0;
	size = ft_check_nums(stack_a);
	while (ft_is_chunk(temp->content, org, pos, min) == 0)
	{
		i++;
		temp = temp->next;
	}
	if (i < (size / 2))
	{
		while (i > 0)
		{
			ft_ra(stack_a);
			i--;
		}
	}
	else
	{
		while (i < size)
		{
			ft_rra(stack_a);
			i++;
		}
	}
	ft_pb(stack_a, stack_b);
}

/*static void	ft_while_rb(t_list **stack_a, t_list **stack_b)
{
	if (ft_locate(stack_b) == 0)
	{
		while ((*stack_b)->content != ft_max(stack_b))
			ft_rb(stack_b);
		ft_pa(stack_a, stack_b);
	}
	else if (ft_locate(stack_b) == 1)
	{
		while ((*stack_b)->content != ft_low(stack_b))
			ft_rb(stack_b);
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
	}
	//ift_pa(stack_a, stack_b);
}

static void	ft_while_rrb(t_list **stack_a, t_list **stack_b)
{
	if (ft_locate(stack_b) == 2)
	{
		while ((*stack_b)->content != ft_max(stack_b))
			ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
	}
	if (ft_locate(stack_b) == 3)
	{
		while ((*stack_b)->content != ft_low(stack_b))
			ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
	}
	//ft_pa(stack_a, stack_b);
}*/

static int	ft_back_to_a(t_list **stack_a, t_list **stack_b, int chk)
{
	int	size;

	size = ft_check_nums(stack_b);
	while (size > 1)
	{
		/*if (ft_locate(stack_b) == 0 || ft_locate(stack_b) == 1)
			ft_while_rb(stack_a, stack_b);
		else
			ft_while_rrb(stack_a, stack_b);*/
		ft_locate(stack_a, stack_b);
		size = ft_check_nums(stack_b);
	}
	ft_pa(stack_a, stack_b);
	//ft_ra(stack_a);
	return (1);
}

static	void	ft_sort_int_tab(int	*org, int	size) // Funciona, no tocar.
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 1;
		while (j < size)
		{
			if (org[j] < org[j - 1])
			{
				temp = org[j];
				org[j] = org[j - 1];
				org[j - 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*ft_organised_array(t_list	*stack_a)
{
	int	i;
	int	*org;
	int	size;
	t_list	*temp;

	size = ft_check_nums(&stack_a);
	temp = stack_a;
	org = malloc(sizeof(int) * size);
	i = 0;
	while (temp)
	{
		org[i] = temp->content;
		temp = temp->next;
		i++;
	}
	ft_sort_int_tab(org, size); // Hasta aqui, funciona :)
	return (org);
}

int	ft_median(t_list *stack_a)
{
	int	i;
	int	size;
	int median;
	t_list	*temp;

	i = 0;
	temp = stack_a;
	size = ft_check_nums(&stack_a);
	median = 0;
	while (i < size)
	{
		median += temp->content;
		temp = temp->next;
		i++;
	}
	median = median / size;
	return (median);
}

static int ft_check_left(t_list **stack_a,int *org, int pos, int min)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->content >= org[min] && temp->content < org[pos])
			return (1);
		temp = temp->next;
	}
	return (0);
}

// Esta función pasa de A a B los menores o iguales que el max del chunck
static void	ft_loop(t_list **stack_a, t_list **stack_b, int pos,int *org, int min)
{
	int i = ft_check_nums(stack_a);
	//printf("ORG[POS] : %i   I: %i\n", org[pos], i);
	while (1)
	{
		if (!ft_check_left(stack_a, org, pos, min))
			break;
		/*if ((*stack_a)->content < org[pos] && (*stack_a)->content >= org[min])
			ft_pb(stack_a, stack_b);*/
		ft_find_chk_nums(stack_a, stack_b, org, pos, min);
		/*else
		{
			if (ft_locate(stack_b) == 0 || ft_locate(stack_b) == 1)
				ft_while_ra(stack_a, stack_b);
			else
				ft_while_rra(stack_a, stack_b);
		}*/

		i--;
	}
}

void	ft_big(t_list **stack_a, t_list **stack_b, int chk)
{
	int		pos;
	int 	size;
	int		*org;
	int		temp;
	int		min;
	int		i = 0;

	org = ft_organised_array(*stack_a);
	size = ft_check_nums(stack_a);
	min = 0;
	pos = (size/chk);
	// Hasta aqui, de nuevo bien ;(
	//printf("POSICION: %i\nSIZE: %i\n", pos, size);
	//printf("Iteracion %i min %i pos %i\n", i, org[min], org[pos]);

	temp = pos;
	while (chk > 0) // 5 v3c3s
	{
		if (chk == 1)
			ft_loop(stack_a, stack_b, (pos - 1), org, min);
		else
			ft_loop(stack_a, stack_b, pos, org, min);
		/*if (i == 9)
		{
			ft_print_lst(stack_a, stack_b);
			exit(0);
		}*/
		//ft_back_to_a(stack_a, stack_b, temp);
		/*if (chk != 1)
			ft_pass(stack_a, pos, org);*/
		min = pos;
		pos += temp;
		if (chk == 1)
			pos = size - 1;
		chk--;
		i++;
	}
	ft_back_to_a(stack_a, stack_b, temp);
	//ft_pass(stack_a, size - 1, org);
	//ft_ra(stack_a);
	ft_print_lst(stack_a, stack_b);
	/*printf("min %i pos %i", min, pos);
	ft_loop(stack_a, stack_b, pos, org, min);
	//ft_back_to_a(stack_a, stack_b, temp);*/
	/*while (org[i] != 21)
	{

	}*/
}

