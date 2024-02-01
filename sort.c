/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:38:16 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/01 14:23:07 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack)
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

void	sort_4(t_list **stack_a, t_list **stack_b)
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

void	sort_5(t_list **stack_a, t_list **stack_b)
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

void	small_sort(t_list **stack_a, t_list **stack_b)
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
int	find_highest_index(t_list *stack)
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

int	find_lowest_index(t_list *stack)
{
	int		index;
	t_list	*temp;

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

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	push_to_b(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		prepare_for_push_b(*stack_a, *stack_b);
		push_to_a(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		get_min_on_top(stack_a);
}
int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}
void	get_min_on_top(t_list **stack)
{
	int	middle;
	int	lowest_index;

	middle = lst_length(*stack) / 2;
	lowest_index = find_min_node(*stack)->index;
	while ((*stack)->index != lowest_index)
	{
		if (lowest_index < middle)
			ra(stack);
		else
			rra(stack);
	}
}

