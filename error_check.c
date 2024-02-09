/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:52:19 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/07 13:44:05 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INT32_MIN || num > INT32_MAX)
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	return ((int)num);
}

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	else
		return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || \
			*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		exit (exit_error());
	while (*str)
	{
		if (!ft_isdigit(*str))
			exit (exit_error());
		result = result * 10 + (*str++ - '0');
	}
	return (result * sign);
}

int	check_duplicate(t_node *stack)
{
	t_node	*dup;
	int		temp;

	if (!stack)
		exit (1);
	while (stack && stack->next)
	{
		temp = stack->content;
		dup = stack;
		while (dup->next)
		{
			dup = dup->next;
			if (dup->content == temp)
			{
				free_stack(&stack);
				write(2, "Error\n", 6);
				exit (1);
			}
		}
		stack = stack->next;
	}
	return (0);
}

void	assign_index(t_node *stack_a)
{
	int		stack_size;
	t_node	*current;
	t_node	*highest;
	int		value;

	stack_size = lst_length(stack_a);
	while (--stack_size > 0)
	{
		current = stack_a;
		highest = NULL;
		value = INT_MIN;
		while (current)
		{
			if (current->index == 0 && current->content >= value)
			{
				value = current->content;
				highest = current;
			}
			current = current->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
