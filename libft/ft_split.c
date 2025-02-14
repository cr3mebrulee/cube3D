/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:30:06 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/07 11:29:41 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extract_word(const char *s, char c, const char **next_word)
{
	const char	*word_start;

	while (*s && *s == c)
		s++;
	word_start = s;
	while (*s && *s != c)
		s++;
	*next_word = s;
	if (word_start != s)
		return (ft_substr(word_start, 0, *next_word - word_start));
	return (NULL);
}

static int	count_words(const char *s, char c)
{
	int	word_count;
	int	in_word;

	word_count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			word_count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (word_count);
}

static void	free_word_array(char **word_arr, int allocated_words)
{
	while (allocated_words >= 0)
		free(word_arr[allocated_words--]);
	free(word_arr);
}

static int	assign_words(char **word_arr, const char *s, char c)
{
	const char	*next_word;
	char		*word;
	int			index;

	index = 0;
	while (*s)
	{
		word = extract_word(s, c, &next_word);
		if (word)
		{
			word_arr[index++] = word;
			s = next_word;
		}
		else if (*next_word)
			s = next_word;
		else
			break ;
	}
	word_arr[index] = NULL;
	return (index);
}

char	**ft_split(char const *s, char c)
{
	char	**word_arr;
	int		word_count;

	if (!s || *s == '\0')
	{
		word_arr = malloc(sizeof(char *));
		if (word_arr)
			word_arr[0] = NULL;
		return (word_arr);
	}
	word_count = count_words(s, c);
	word_arr = malloc((word_count + 1) * sizeof(char *));
	if (!word_arr)
		return (NULL);
	if (assign_words(word_arr, s, c) == -1)
	{
		free_word_array(word_arr, word_count);
		return (NULL);
	}
	return (word_arr);
}
