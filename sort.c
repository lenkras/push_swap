/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:38:16 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/06 14:42:40 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **stack)
{
	int		max;

	max = find_highest_index(*stack);
	if ((*stack)->index == max)
		ra(stack);
	else if ((*stack)->next->index == max)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int	min_index;

	min_index = find_lowest_index(*stack_a);
	if ((*stack_a)->index != min_index)
	{
		while ((*stack_a)->index != min_index)
		{
			if (min_index == ft_lstlast(*stack_a)->index || \
			min_index == ft_lstlast(*stack_a)->prev->index)
				rra(stack_a);
			else
				ra(stack_a);
		}
	}
	if ((*stack_a)->index == min_index)
	{
		pb(stack_a, stack_b);
		sort_3(stack_a);
		pa(stack_a, stack_b);
	}
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	min_index;

	while (lst_length(*stack_a) > 3)
	{
		min_index = find_lowest_index(*stack_a);
		while ((*stack_a)->index != min_index)
		{
			if (min_index == ft_lstlast(*stack_a)->index || \
			min_index == ft_lstlast(*stack_a)->prev->index)
				rra(stack_a);
			else
				ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	small_sort(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;

	stack_size = lst_length(*stack_a);
	if (stack_size == 2)
		sa(stack_a);
	if (stack_size == 3)
		sort_3(stack_a);
	if (stack_size == 4)
		sort_4(stack_a, stack_b);
	if (stack_size == 5)
		sort_5(stack_a, stack_b);
}

int	is_sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}
