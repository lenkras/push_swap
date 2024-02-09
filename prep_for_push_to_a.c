/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_for_push_to_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:28:26 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/09 15:49:05 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_node **stack_a, t_node **stack_b)
{
	int		stack_size;
	int		pushed;	

	stack_size = lst_length(*stack_a);
	pushed = 0;
	while (pushed < stack_size / 2)
	{
		if ((*stack_a)->index < stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
	while (stack_size - pushed > 3)
	{
		if ((*stack_a)->index < stack_size - 3)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
}

void	target_for_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*a_current;
	t_node	*target_node;
	long	close_bigger_index;

	while (stack_b)
	{
		close_bigger_index = LONG_MAX;
		a_current = stack_a;
		while (a_current)
		{
			if (a_current->index > stack_b->index && \
			a_current->index < close_bigger_index)
			{
				close_bigger_index = a_current->index;
				target_node = a_current;
			}
			a_current = a_current->next;
		}
		if (close_bigger_index == LONG_MAX)
			stack_b->target_node = find_min_node(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	prepare_to_push_b(t_node *stack_a, t_node *stack_b)
{
	get_position(stack_a);
	get_position(stack_b);
	target_for_b(stack_a, stack_b);
	calculate_cost(stack_a, stack_b);
	find_cheapest(stack_b);
}
