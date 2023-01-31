/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:43:11 by marmulle          #+#    #+#             */
/*   Updated: 2022/11/29 12:52:35 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	h;

	if (haystack == needle || !ft_strlen(needle))
		return ((char *)haystack);
	h = 0;
	while (h < len && haystack[h] != '\0')
	{
		n = 0;
		while (n < len
			&& h < len
			&& haystack[h] == needle[n]
			&& haystack[h] != '\0')
		{
			++h;
			++n;
		}
		if (needle[n] == '\0')
			return ((char *)(haystack + h - n));
		else
			h -= n;
		++h;
	}
	return (NULL);
}
