/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:45:26 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/01 15:04:33 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	if (argc > 1)
	{
		put_in_stack(argc, argv, &stack_a);
		if (!is_sorted(stack_a))
		{
			if (lst_length(stack_a) <= 5)
				small_sort(&stack_a, &stack_b);
			else
				big_sort(&stack_a, &stack_b);
		}
		//print_list(stack_a);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}



// int	main(int argc, char **argv)
// {
// 	t_list	*a_stack = NULL;
// 	t_list	*b_stack = NULL;

// 	if (argc == 1)
// 	{
// 		write (2, "Error\n", 6);
// 		exit (1);
// 	}
// 	if (argc > 1)
// 	{
// 		put_in_stack(argc, argv, &a_stack);
// 		print_list(a_stack);
// 		//big_sort(&a_stack, &b_stack);
// 		sort_5(&a_stack, &b_stack);
// 		print_list(a_stack);
// 		// write(1, "left in a\n", 10);
// 		// push_to_b(&a_stack, &b_stack);
// 		// print_list(a_stack);
// 		// write(1, "pushed\n", 7);
// 		// print_list(b_stack);
// 		// write(1, "sort\n", 5);
// 		// sort_3(&a_stack);
// 		// print_list(a_stack);
// 		// write (1, "target\n", 7);
// 		// target_for_b(a_stack, b_stack);
// 		// print_list(a_stack);
// 		// print_list(b_stack);
// 		// pa(&a_stack, &b_stack);
// 		// write (1, "a stack\n", 8);
// 		// print_list(a_stack);
// 		// write (1, "b stack\n", 8);
// 		// print_list(b_stack);
// 		// write (1, "target\n", 7);
// 		// target_for_b(a_stack, b_stack);
// 		// print_list(b_stack);
// 		// print_node(b_stack);

// // 		// pa(&a_stack, &b_stack);
// // 		// write (1, "a stack\n", 8);
// // 		// print_list(a_stack);
// // 		// write (1, "b stack\n", 8);
// // 		// print_list(b_stack);
// // 		// write (1, "target\n", 7);
// // 		// target_for_b(a_stack, b_stack);
// // 		// print_list(b_stack);
// // 		// print_node(b_stack);


// // 		// pa(&a_stack, &b_stack);
// // 		// write (1, "a stack\n", 8);
// // 		// print_list(a_stack);
// // 		// write (1, "b stack\n", 8);
// // 		// print_list(b_stack);
// // 		// write (1, "target\n", 7);
// // 		// target_for_b(a_stack, b_stack);
// // 		// print_list(b_stack);
// // 		// print_node(b_stack);

		
// // 		//ra(&a_stack);
// // 		//print_list(a_stack);
// // 		// rra(&a_stack);
// // 		// print_list(a_stack);
// // 		// write(1, "\n", 1);
// // 		// sa(&a_stack);
// // 		// print_list(a_stack);
// // 		// pb(&a_stack, &b_stack);
// // 		// print_list(a_stack);
// // 		// write(1, "\n", 1);
// // 		// print_list(b_stack);
// 	}
// 	return (0);
// }
