
#include "push_swap.h"

void	ft_big(t_list **stack_a, t_list **stack_b, int chk)
{
	int		pos;
	int 	size;
	int		*org;
	int		temp;
	int		min;

	org = ft_organised_array(*stack_a);
	size = ft_check_nums(stack_a);
	min = 0;
	pos = (size/chk);
	temp = pos;
	while (chk > 0)
	{
		if (chk == 1)
			ft_loop(stack_a, stack_b, (pos - 1), org, min);
		else
			ft_loop(stack_a, stack_b, pos, org, min);
		min = pos;
		pos += temp;
		if (chk == 1)
			pos = size - 1;
		chk--;
	}
	ft_back_to_a(stack_a, stack_b, temp);
}
