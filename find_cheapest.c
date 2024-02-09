/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:59:15 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/09 17:47:54 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_cheapest_node(t_node *node, long *cheapest_value, \
			t_node **cheapest_node)
{
	if (node->push_cost < *cheapest_value)
	{
		*cheapest_value = node->push_cost;
		*cheapest_node = node;
	}
}

void	find_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;
	int		len;
	int		max_index;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	cheapest_node = NULL;
	len = lst_length(stack);
	max_index = find_highest_index(stack);
	while (stack)
	{
		if (len <= 100 && stack->index >= max_index - 15)
			update_cheapest_node(stack, &cheapest_value, &cheapest_node);
		else if (len <= 500 && len > 100 && stack->index >= max_index - 65)
			update_cheapest_node(stack, &cheapest_value, &cheapest_node);
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

t_node	*get_cheapest_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

