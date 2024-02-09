/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:31:10 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/06 14:42:40 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	int	temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	temp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = temp;
}

void	sa(t_node **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_node **a_stack, t_node **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	write(1, "ss\n", 3);
}
