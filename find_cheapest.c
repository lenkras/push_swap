/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:59:15 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/10 18:19:52 by epolkhov         ###   ########.fr       */
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

t_node	*find_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;
	int		len;
	int		max_index;

	if (!stack)
		return (NULL);
	cheapest_value = LONG_MAX;
	cheapest_node = NULL;
	len = lst_length(stack);
	max_index = find_highest_index(stack);
	while (stack)
	{
		if (len <= 100 && stack->index >= max_index - 10)
			update_cheapest_node(stack, &cheapest_value, &cheapest_node);
		if (len <= 500 && len > 100 && stack->index >= max_index - 85)
			update_cheapest_node(stack, &cheapest_value, &cheapest_node);
		stack = stack->next;
	}
	return (cheapest_node);
}
