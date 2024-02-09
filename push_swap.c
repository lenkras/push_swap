/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:45:26 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/09 16:39:49 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (argc > 1)
	{
		put_in_stack(argc, argv, &stack_a);
		check_duplicate(stack_a);
		assign_index(stack_a);
		if (!is_sorted(stack_a))
		{
			if (lst_length(stack_a) <= 5)
				small_sort(&stack_a, &stack_b);
			else
				big_sort(&stack_a, &stack_b);
		}
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}

int	put_in_stack(int argc, char **argv, t_node **a_stack)
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
		if (!(array[j] || !array))
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
		free_array(array);
		i++;
	}
	return (0);
}

void	big_sort(t_node **stack_a, t_node **stack_b)
{
	push_to_b(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		prepare_to_push_b(*stack_a, *stack_b);
		push_to_a(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		get_min_on_top(stack_a);
}

void	get_min_on_top(t_node **stack)
{
	int		middle;
	t_node	*lowest_node;

	middle = lst_length(*stack) / 2;
	lowest_node = find_min_node(*stack);
	if (!stack || !*stack)
		return ;
	while (*stack != lowest_node)
	{
		if (lowest_node->position < middle)
			ra(stack);
		else
			rra(stack);
	}
}
