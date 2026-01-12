/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:09:24 by gumendes          #+#    #+#             */
/*   Updated: 2026/01/12 16:55:36 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Allocates a substring from s[start] to s[end-1] */
static char	*fill_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

/* Frees partially allocated array on error */
static void	*ft_free(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

/* Counts words including empty strings for consecutive delimiters */
static int	word_count(const char *s, char delim)
{
	int	count;
	int	i;

	if (!*s)
		return (1);
	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == delim)
			count++;
		i++;
	}
	return (count);
}

/* Fills the array with words, creating empty
 strings for consecutive delimiters */
static char	**split_words(char **res, const char *s, char delim)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] == delim)
		{
			res[j++] = fill_word(s, start, i);
			if (!res[j - 1])
				return (ft_free(res, j - 1));
			start = i + 1;
		}
		i++;
	}
	res[j++] = fill_word(s, start, i);
	if (!res[j - 1])
		return (ft_free(res, j - 1));
	res[j] = NULL;
	return (res);
}

char	**ft_special_split(const char *s, char delim)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (word_count(s, delim) + 1));
	if (!res)
		return (NULL);
	return (split_words(res, s, delim));
}
