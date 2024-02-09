/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:46:48 by epolkhov          #+#    #+#             */
/*   Updated: 2024/02/06 16:49:22 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
