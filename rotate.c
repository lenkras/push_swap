/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:02:50 by epolkhov          #+#    #+#             */
/*   Updated: 2024/01/16 16:35:03 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = ft_lstlast(*stack);
	temp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->prev = temp;
	temp->next->next = NULL;
}

void	ra(t_list **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_list **a_stack, t_list **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	write(1, "rr\n", 3);
}
