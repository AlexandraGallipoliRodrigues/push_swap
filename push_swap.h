/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancarlospopapopa <juancarlospopapopa@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:48:18 by agallipo          #+#    #+#             */
/*   Updated: 2021/10/13 22:30:05 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

char	*ft_strchr(const char *str, int c);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(int	content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
int		ft_atoi(const char *str);
void	ft_three(t_list **stack_a);
void	ft_five(t_list **stack_a, t_list **stack_b);
int		ft_low(t_list	**stack_a);
int		ft_max(t_list	**stack_a);
int		ft_check_nums(t_list **stack_a);
void	ft_print_lst(t_list **stack_a, t_list **stack_b);
int		*ft_organised_array(t_list *stack_a);
int		ft_median(t_list	*stack_a);
int		ft_check_error(t_list *stack_a);
#endif
