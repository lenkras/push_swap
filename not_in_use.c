/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_in_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:47:53 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/06 11:49:45 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
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
