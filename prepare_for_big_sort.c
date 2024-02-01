/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_for_big_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:35:22 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/01 15:03:50 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_list *stack)
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

void	assign_index(t_list *stack_a)
{
	int		stack_size;
	t_list	*current;
	t_list	*highest;
	int		value;

	stack_size = lst_length(stack_a);
	while (--stack_size > 0)
	{
		current = stack_a;
		highest = NULL;
		value = INT_MIN;
		while (current)
		{
			if (current->index == 0 && current->content >= value)
			{
				value = current->content;
				highest = current;
			}
			current = current->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

void	target_for_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*a_current;
	t_list	*target_node;
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

void	push_to_b(t_list **stack_a, t_list **stack_b)
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

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;
	int		size_b;
	int		size_a;

	size_b = lst_length(*stack_b);
	size_a = lst_length(*stack_a);
	cheapest_node = get_cheapest_node(*stack_b);
	while (*stack_b != cheapest_node || *stack_a != cheapest_node->target_node)
	{
		if (cheapest_node->position < size_b / 2 && \
		cheapest_node->target_node->position < size_a / 2)
		{
			while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
				rr(stack_a, stack_b);
			while (*stack_a != cheapest_node->target_node)
				ra(stack_a);
			while (*stack_b != cheapest_node)
				rb(stack_b);
		}
		else if (cheapest_node->position >= size_b / 2 && \
		cheapest_node->target_node->position >= size_a / 2)
		{
			while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
				rrr(stack_a, stack_b);
			while (*stack_a != cheapest_node->target_node)
				rra(stack_a);
			while (*stack_b != cheapest_node)
				rrb(stack_b);
		}
		else if (cheapest_node->position < size_b / 2 && \
		cheapest_node->target_node->position >= size_a / 2)
			do_rb_rra(stack_a, stack_b, cheapest_node);
		else
			do_ra_rrb(stack_a, stack_b, cheapest_node);
	}
	pa(stack_a, stack_b);
}

void	do_rb_rra(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
		while (*stack_b != cheapest_node)
			rb (stack_b);
		while (*stack_a != cheapest_node->target_node)
			rra(stack_a);
}
void	do_ra_rrb(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
		while (*stack_b != cheapest_node)
			rrb (stack_b);
		while (*stack_a != cheapest_node->target_node)
			ra(stack_a);
}


void	calculate_cost(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = lst_length(stack_a);
	len_b = lst_length(stack_b);
	while (stack_b)
	{
		stack_b->push_cost = stack_b->position;
		if (stack_b->position > len_b / 2)
			stack_b->push_cost = len_b - stack_b->position;
		if (stack_b->target_node->position < len_a / 2)
		{	
			if (stack_b->target_node->position < len_a / 2 && stack_b->position < len_b / 2 && stack_b->target_node->position > stack_b->position)
				stack_b->push_cost = stack_b->target_node->position;
		}
		else
		{
			if (stack_b->target_node->position > len_a / 2 && stack_b->position > len_b / 2 && stack_b->target_node->position < stack_b->position)
				stack_b->push_cost = len_b - stack_b->position;
			else
				stack_b->push_cost = len_a - stack_b->target_node->position;
		}
		stack_b = stack_b->next;
	}
}

void	find_cheapest(t_list *stack)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	prepare_for_push_b(t_list *stack_a, t_list *stack_b)
{
	get_position(stack_a);
	get_position(stack_b);
	target_for_b(stack_a, stack_b);
	calculate_cost(stack_a, stack_b);
	find_cheapest(stack_b);
}

t_list	*get_cheapest_node(t_list *stack)
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
