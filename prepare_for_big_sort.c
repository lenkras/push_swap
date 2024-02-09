/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_for_big_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:35:22 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/09 17:17:19 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;
	int		size_b;
	int		size_a;

	size_b = lst_length(*stack_b);
	size_a = lst_length(*stack_a);
	cheapest_node = get_cheapest_node(*stack_b);
	if (cheapest_node->position < size_b / 2 && \
		cheapest_node->target_node->position < size_a / 2)
		do_rr_ra_rb(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->position >= size_b / 2 && \
		cheapest_node->target_node->position >= size_a / 2)
		do_rrr(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->position < size_b / 2 && \
			cheapest_node->target_node->position >= size_a / 2)
		do_rb_rra(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->position >= size_b / 2 && \
			cheapest_node->target_node->position < size_a / 2)
		do_ra_rrb(stack_a, stack_b, cheapest_node);
	pa(stack_a, stack_b);
}

void	do_rb_rra(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_b != cheapest_node)
		rb (stack_b);
	while (*stack_a != cheapest_node->target_node)
		rra(stack_a);
}

void	do_ra_rrb(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_b != cheapest_node)
		rrb (stack_b);
	while (*stack_a != cheapest_node->target_node)
		ra(stack_a);
}

void	do_rr_ra_rb(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rr(stack_a, stack_b);
	while (*stack_a != cheapest_node->target_node)
		ra(stack_a);
	while (*stack_b != cheapest_node)
		rb(stack_b);
}

void	do_rrr(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rrr(stack_a, stack_b);
	while (*stack_a != cheapest_node->target_node)
		rra(stack_a);
	while (*stack_b != cheapest_node)
		rrb(stack_b);
}
