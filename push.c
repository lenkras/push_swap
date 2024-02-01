/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:51:58 by epolkhov          #+#    #+#             */
/*   Updated: 2024/01/15 17:18:40 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **src, t_list **dest)
{
	t_list	*temp;

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

void	pa(t_list **a_stack, t_list **b_stack)
{
	push(b_stack, a_stack);
	write(1, "pa\n", 3);
}

void	pb(t_list **a_stack, t_list **b_stack)
{
	push(a_stack, b_stack);
	write(1, "pb\n", 3);
}
