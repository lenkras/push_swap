/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:35:55 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/07 13:05:14 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_mod(t_node **lst, t_node *new)
{
	t_node	*newnode;

	newnode = *lst;
	if (lst == NULL || new == NULL)
		return ;
	if (!(*lst))
	{
		*lst = new;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
		return ;
	}
	else
	{
		while (newnode -> next != NULL)
			newnode = newnode -> next;
		newnode -> next = new;
		new->prev = newnode;
	}
}

void	ft_lstadd_front_mod(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
		return ;
	}
	(*lst)->prev = new;
	new -> next = *lst;
	*lst = new;
	new->prev = NULL;
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

t_node	*ft_lstnew_mod(int content)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode -> content = content;
	newnode -> next = NULL;
	newnode -> prev = NULL;
	return (newnode);
}

long	lst_length(t_node *stack)
{
	long	len;

	len = 0;
	if (!stack)
		return (1);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
