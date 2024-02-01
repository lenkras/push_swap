/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:52:22 by epolkhov          #+#    #+#             */
/*   Updated: 2024/01/15 17:18:32 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_list **stack)
{
	t_list	*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = ft_lstlast(*stack);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->prev;
}

void	rra(t_list **stack)
{
	reverse(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack)
{
	reverse(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a_stack, t_list **b_stack)
{
	reverse(a_stack);
	reverse(b_stack);
	write(1, "rrr\n", 4);
}
