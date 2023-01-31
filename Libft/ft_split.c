/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:07:52 by marmulle          #+#    #+#             */
/*   Updated: 2022/11/29 13:10:43 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++count;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

static char	**ft_cleanup(char **split, int w)
{
	while (--w >= 0)
		free(split[w]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_len;
	int		w;

	if (!s)
		return (NULL);
	split = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	w = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (!(*s))
			return (split);
		word_len = 0;
		while (s[word_len] != '\0' && s[word_len] != c)
			++word_len;
		split[w] = ft_substr(s, 0, word_len);
		if (!split[w++])
			return (ft_cleanup(split, w));
		s += word_len;
	}
	return (split);
}
