/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:40:14 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/07 13:33:42 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*current;

	current = *stack;
	if (!stack)
		return ;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i] != NULL)
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
	}
	if (array != NULL)
	{
		free(array);
		array = NULL;
	}
}

int	exit_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
