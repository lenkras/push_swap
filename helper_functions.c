/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:57:32 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/06 14:42:40 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->position = i;
		stack = stack->next;
		i++;
	}
}

int	find_highest_index(t_node *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

int	find_lowest_index(t_node *stack)
{
	int		index;
	t_node	*temp;

	if (!stack)
		return (1);
	temp = stack;
	index = temp->index;
	while (temp)
	{
		if (temp->index < index)
			index = temp->index;
		temp = temp->next;
	}
	return (index);
}

t_node	*find_max_node(t_node *stack)
{
	long	max;
	t_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_node	*find_min_node(t_node *stack)
{
	long	min;
	t_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
