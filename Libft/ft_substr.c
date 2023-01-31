/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:54:59 by marmulle          #+#    #+#             */
/*   Updated: 2022/11/11 17:35:02 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_len;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= (unsigned int)s_len)
		return (ft_strdup(""));
	sub_len = s_len - (size_t)start;
	if (sub_len > len)
		sub_len = len;
	sub = (char *)ft_calloc(sub_len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = -1;
	while (++i < sub_len)
		sub[i] = s[start + i];
	return (sub);
}
