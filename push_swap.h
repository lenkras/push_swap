/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:04 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/01 13:34:07 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	int				index;
	int				content;
	int				position;
	int				push_cost;
	bool			cheapest;
	int				target_position;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	ft_lstadd_back_mod(t_list **lst, t_list *new);
void	ft_lstadd_front_mod(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew_mod(int content);
long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
void	print_list(t_list *head);
int		put_in_stack(int argc, char **argv, t_list **a_stack);
void	reverse(t_list **stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **a_stack, t_list **b_stack);
void	rotate(t_list **stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **a_stack, t_list **b_stack);
void	swap(t_list **stack);
void	sa(t_list **stack);
void	push(t_list **src, t_list **dest);
void	pb(t_list **a_stack, t_list **b_stack);
void	pa(t_list **a_stack, t_list **b_stack);
int		error_check(char *str);
int		ft_isdigit(int arg);
int		ft_atoi(const char *str);
int		check_duplicate(t_list *stack);
t_list	*find_max_node(t_list *stack);
void	sort_3(t_list **stack);
t_list	*find_min_node(t_list *stack);
long	lst_length(t_list *stack);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	target_for_b(t_list *stack_a, t_list *stack_b);
void	assign_index(t_list *stack);
int		find_highest_index(t_list *stack);
void	get_position(t_list *stack);
int		find_lowest_index(t_list *stack);
void	print_node(t_list *head);
t_list	*get_cheapest_node(t_list *stack);
void	prepare_for_push_b(t_list *stack_a, t_list *stack_b);
void	find_cheapest(t_list *stack);
void	calculate_cost(t_list *stack_a, t_list *stack_b);
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b);
void	do_rb_rra(t_list **stack_a, t_list **stack_b, t_list *cheapest_node);
void	do_ra_rrb(t_list **stack_a, t_list **stack_b, t_list *cheapest_node);
int		is_sorted(t_list *stack);
void	get_min_on_top(t_list **stack);
void	free_stack(t_list **stack);
void	error_free(t_list **stack);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	small_sort(t_list **stack_a, t_list **stack_b);

#endif
