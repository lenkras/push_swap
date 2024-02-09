/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:04 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/09 16:40:05 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				index;
	int				content;
	int				position;
	int				push_cost;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

///////////// manipulate lists //////////////

void	ft_lstadd_back_mod(t_node **lst, t_node *new);
void	ft_lstadd_front_mod(t_node **lst, t_node *new);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew_mod(int content);
long	lst_length(t_node *stack);

////////////////// operations ////////////////

void	reverse(t_node **stack);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **a_stack, t_node **b_stack);
void	rotate(t_node **stack);
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **a_stack, t_node **b_stack);
void	swap(t_node **stack);
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **a_stack, t_node **b_stack);
void	push(t_node **src, t_node **dest);
void	pb(t_node **a_stack, t_node **b_stack);
void	pa(t_node **a_stack, t_node **b_stack);

/////////////// helper functions ////////////////

long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
t_node	*find_max_node(t_node *stack);
t_node	*find_min_node(t_node *stack);
void	assign_index(t_node *stack);
void	get_position(t_node *stack);
int		find_highest_index(t_node *stack);
int		find_lowest_index(t_node *stack);
int		ft_isdigit(int arg);

////////////// assign input to list //////////////

int		error_check(char *str);
int		check_duplicate(t_node *stack);
int		put_in_stack(int argc, char **argv, t_node **a_stack);

void	push_to_b(t_node **stack_a, t_node **stack_b);
void	target_for_b(t_node *stack_a, t_node *stack_b);
void	prepare_to_push_b(t_node *stack_a, t_node *stack_b);
void	push_to_a(t_node **stack_a, t_node **stack_b);
void	do_rb_rra(t_node **stack_a, t_node **stack_b, t_node *cheapest_node);
void	do_ra_rrb(t_node **stack_a, t_node **stack_b, t_node *cheapest_node);
void	do_rr_ra_rb(t_node **stack_a, t_node **stack_b, t_node *cheapest_node);
void	do_rrr(t_node **stack_a, t_node **stack_b, t_node *cheapest_node);

/////////////////// cost /////////////////////

t_node	*get_cheapest_node(t_node *stack);
void	find_cheapest(t_node *stack);
void	calculate_cost(t_node *stack_a, t_node *stack_b);
void	initialize_positions(t_node *stack, int *position_a, int *position_b);
void	calculate_push_cost(t_node *a, t_node *b, int len_a, int len_b);

////////////////// sort ////////////////////

void	sort_3(t_node **stack);
void	sort_4(t_node **stack_a, t_node **stack_b);
void	sort_5(t_node **stack_a, t_node **stack_b);
void	small_sort(t_node **stack_a, t_node **stack_b);
void	big_sort(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node *stack);
void	get_min_on_top(t_node **stack);

void	free_stack(t_node **stack);
void	free_array(char **array);
int		exit_error(void);

#endif
