/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:28:31 by agallipo          #+#    #+#             */
/*   Updated: 2021/11/03 12:38:37 by agallipo         ###   ########.fr       */
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
static void	ft_while_rb(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_b)->content != ft_max(stack_b))
		ft_rb(stack_b);
	ft_pa(stack_a, stack_b);
}

static void	ft_while_rrb(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_b)->content != ft_max(stack_b))
		ft_rrb(stack_b);
	ft_pa(stack_a, stack_b);
}

static int	ft_locate(t_list **stack_b)
{
	t_list	*temp;
	int		i;
	int		size;

	i = 0;
	temp = *stack_b;
	size = ft_check_nums(stack_b);
	while (temp->content != ft_max(stack_b))
	{
		temp = temp->next;
		i++;
	}
	if (i < (size / 2))
		return (0);
	return (1);
}
static int	ft_back_to_a(t_list **stack_a, t_list **stack_b, int chk)
{
	int	size;
	int	i;
	
	i = 1;
	size = ft_check_nums(stack_b);
	while (size > 1)
	{
		if (ft_locate(stack_b) == 0)
			ft_while_rb(stack_a, stack_b);
		else
			ft_while_rrb(stack_a, stack_b);
		size = ft_check_nums(stack_b);
		i++;
	}
	ft_pa(stack_a, stack_b);
	return (1);

}
static	void	ft_sort_int_tab(int	*org, int	size)
{
	int	x;
	int	y;
	int	temp;

	x = 0;
	while (x <= size - 1)
	{
		y = 0;
		while (y <= size - 2)
		{
			if (org[y] > org[x])
			{
				temp = org[x];
				org[x] = org[y];
				org[y] = temp;
			}
			y++;
		}
		x++;
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
	while (i < size && temp)
	{
		org[i] = temp->content;
		temp = temp->next;
		i++;
	}
	ft_sort_int_tab(org, size);
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

static void	ft_loop(t_list **stack_a, t_list **stack_b, int pos,int *org, int t)
{
	int	i;

	i = ft_check_nums(stack_a);
//	printf("ORG[POS] : %i\n", org[pos]);
	while (i >= 0 && *stack_a)
	{
		if ((*stack_a)->content <= org[pos])
		{
			printf("ORG[POS] %i %i\n", org[pos], org[pos] / 2);
			if ((*stack_a)->content <= org[pos - t])
			{
				ft_pb(stack_a, stack_b);
				ft_rb(stack_b);
			}
			else
				ft_pb(stack_a, stack_b);
		}
		else
			ft_rra(stack_a);
		i--;
	}
}

void	ft_big(t_list **stack_a, t_list **stack_b, int chk)
{
	int		pos;
	int 	size;
	int		*org;
	int		temp;

	temp = chk;
	org = ft_organised_array(*stack_a);
	size = ft_check_nums(stack_a);
	pos = size/chk;
	while (chk > 0)
	{
		//printf("POSICION: %i\nSIZE: %i\n", pos, size);
		ft_loop(stack_a, stack_b, pos, org, (size / temp) / 2);
		ft_back_to_a(stack_a, stack_b, temp);
		pos += pos;
		if (pos > size)
			pos = size - 1;
		chk--;
	}
	//ft_back_to_a(stack_a, stack_b, temp);
	//ft_print_lst(stack_a, stack_b);
}

