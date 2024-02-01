/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:40:14 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/01 11:19:48 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*current;

	current = *stack;
	if (!stack)
		return ;
	while (current)
	{
		temp = current->next;
		current->content = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	error_free(t_list **stack)
{
	free_stack(stack);
	write (2, "Error\n", 6);
	exit (1);
}
