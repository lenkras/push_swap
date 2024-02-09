/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:36:42 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/09 17:02:44 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_positions(t_node *stack, int *position_a, int *position_b)
{
	*position_a = stack->target_node->position;
	*position_b = stack->position;
}

static void	check_pos(t_node *stack, int position_a, int position_b)
{
	if (position_a > position_b)
		stack->push_cost = position_a;
	else
		stack->push_cost = position_b;
}

void	calculate_push_cost(t_node *a, t_node *b, int len_a, int len_b)
{
	int	position_a;
	int	position_b;

	initialize_positions(b, &position_a, &position_b);
	b->push_cost = position_b;
	if (position_b < len_b / 2)
	{
		if (position_a < len_a / 2)
			check_pos(b, position_a, position_b);
		else
			b->push_cost = position_b + (len_a - position_a);
	}
	if (position_b >= len_b / 2)
	{
		if (position_a >= len_a / 2)
		{
			if (position_a < position_b)
				b->push_cost = len_a - position_a;
			else
				b->push_cost = len_b - position_b;
		}
		else
			b->push_cost = (len_b - position_b) + position_a;
	}
}

void	calculate_cost(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = lst_length(stack_a);
	len_b = lst_length(stack_b);
	while (stack_b)
	{
		calculate_push_cost(stack_a, stack_b, len_a, len_b);
		stack_b = stack_b->next;
	}
}
