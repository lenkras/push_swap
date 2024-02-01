/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:31:10 by epolkhov          #+#    #+#             */
/*   Updated: 2024/01/23 14:24:33 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
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

void	sa(t_list **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_list **a_stack, t_list **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	write(1, "ss\n", 3);
}
