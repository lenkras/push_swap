/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:52:19 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/01 14:11:27 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d %d\n", head -> content, head->index);
		head = head -> next;
	}
}
void	print_node(t_list *head)
{
		printf("Target node %d\n", head -> target_node->index);
		//head = head -> next;
}

int	error_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || (ft_atol(str) < INT32_MIN || \
		ft_atol(str) > INT32_MAX))
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
	return (ft_atol(str));
}

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	else
		return (0);
}

int	put_in_stack(int argc, char **argv, t_list **a_stack)
{
	int		i;
	int		j;
	char	**array;
	int		input;

	i = 1;
	while (i < argc)
	{
		array = ft_split(argv[i], ' ');
		j = 0;
		if (!array[j])
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		while (array[j])
		{
			input = error_check(array[j]);
			ft_lstadd_back_mod(a_stack, ft_lstnew_mod(input));
			j++;
		}
		free(array);
		i++;
	}
	check_duplicate(*a_stack);
	assign_index(*a_stack);
	//print_list(*a_stack);
	return (0);
}

// static long	convert_nb(const char *str, long nb, long sign)
// {
// 	long	i;

// 	i = 0;
// 	while (str[i] && (str[i] >= 48 && str[i] <= 57))
// 	{
// 		if (nb > LONG_MAX / 10)
// 		{
// 			if (sign < 0)
// 				return (0);
// 			return (-1);
// 		}
// 		nb = nb * 10;
// 		if (nb > LONG_MAX - (str[i] - 48))
// 		{
// 			if (sign < 0)
// 				return (0);
// 			return (-1);
// 		}
// 		nb = nb + (str[i] - 48);
// 		i++;
// 	}
// 	return (nb);
// }

// long	ft_atol(const char *str)
// {
// 	size_t	i;
// 	long	nb;
// 	long	sign;

// 	nb = 0;
// 	i = 0;
// 	sign = 1;
// 	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
// 		i++;
// 	if (str[i] == '-')
// 		sign = sign * (-1);
// 	if (str[i] == '-' || str[i] == '+')
// 		i++;
// 	nb = convert_nb(str + i, nb, sign);
// 	return (nb * sign);
// }

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
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}


int	check_duplicate(t_list *stack)
{
	t_list	*dup;
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
				write (2, "Error\n", 6);
				exit (1);
			}
		}
		stack = stack->next;
	}
	return (0);
}
