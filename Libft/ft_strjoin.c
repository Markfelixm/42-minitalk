/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:04:23 by marmulle          #+#    #+#             */
/*   Updated: 2022/11/07 19:26:39 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_joinlen(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	total_len = 0;
	if (s1)
	{
		s1_len = ft_strlen(s1);
		total_len += s1_len;
	}
	if (s2)
	{
		s2_len = ft_strlen(s2);
		total_len += s2_len;
	}
	return (total_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*join;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	total_len = ft_joinlen(s1, s2);
	if (!total_len)
		return (ft_strdup(""));
	join = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		join[i++] = *(s1++);
	while (s2 && *s2)
		join[i++] = *(s2++);
	join[i] = '\0';
	return (join);
}
