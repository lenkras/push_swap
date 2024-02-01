/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:35:55 by epolkhov          #+#    #+#             */
/*   Updated: 2024/01/30 17:17:23 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_mod(t_list **lst, t_list *new)
{
	t_list	*newnode;

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

void	ft_lstadd_front_mod(t_list **lst, t_list *new)
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

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

t_list	*ft_lstnew_mod(int content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode -> content = content;
	newnode -> next = NULL;
	newnode -> prev = NULL;
	return (newnode);
}

t_list	*find_max_node(t_list *stack)
{
	long	max;
	t_list	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_list	*find_min_node(t_list *stack)
{
	long	min;
	t_list	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

long	lst_length(t_list *stack)
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


static int	wordcount(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*wordtoprint(const char **s, char c)
{
	int			i;
	char		*word;
	const char	*str;

	str = *s;
	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (*str && *str != c)
	{
		word[i] = *str;
		i++;
		str++;
	}
	word[i] = '\0';
	*s = str;
	return (word);
}

/**
 * 1.The first while loop skips leading delimiters.
 * 2. The second while loop calculates the length i 
 * 	of the word until the next delimiter.
 * 3. The loop copies characters from str to word, constructing the word.
 * 4. The pointer s is moved to the next position after the word.
 */

static void	free_all(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**newstr;
	int		i;

	if (!s)
		return (NULL);
	len = wordcount(s, c);
	newstr = (char **)malloc((len + 1) * sizeof(char *));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstr[i] = wordtoprint(&s, c);
		if (newstr[i] == NULL)
		{
			free_all(i, newstr);
			return (NULL);
		}
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}

static int	convert_nb(const char *str, long nb, int sign)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		if (nb > LONG_MAX / 10)
		{
			if (sign < 0)
				return (0);
			return (-1);
		}
		nb = nb * 10;
		if (nb > LONG_MAX - (str[i] - 48))
		{
			if (sign < 0)
				return (0);
			return (-1);
		}
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	nb;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = sign * (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = convert_nb(str + i, nb, sign);
	return ((int)nb * sign);
}
