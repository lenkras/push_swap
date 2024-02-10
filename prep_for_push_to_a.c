/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_for_push_to_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:28:26 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/10 18:13:40 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_elements(t_node **a, t_node **b, int pushed, int target_index)
{
	while (pushed < target_index)
	{
		if ((*a)->index < target_index)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
	return (pushed);
}

static void	push_remaining_elements(t_node **a, t_node **b, int pushed, int len)
{
	while (len - pushed > 3)
	{
		if ((*a)->index < len - 3)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
}

void	push_to_b(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;
	int	pushed;

	stack_size = lst_length(*stack_a);
	pushed = 0;
	pushed = push_elements(stack_a, stack_b, pushed, stack_size / 4);
	pushed = push_elements(stack_a, stack_b, pushed, stack_size / 2);
	pushed = push_elements(stack_a, stack_b, pushed, stack_size / 4 * 3);
	push_remaining_elements(stack_a, stack_b, pushed, stack_size);
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
}
