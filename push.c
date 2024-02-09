/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:51:58 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/06 14:42:40 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = temp->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	if (*dest != NULL)
		(*dest)->prev = temp;
	temp->next = *dest;
	temp->prev = NULL;
	*dest = temp;
}

void	pa(t_node **a_stack, t_node **b_stack)
{
	push(b_stack, a_stack);
	write(1, "pa\n", 3);
}

void	pb(t_node **a_stack, t_node **b_stack)
{
	push(a_stack, b_stack);
	write(1, "pb\n", 3);
}
