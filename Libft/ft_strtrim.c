/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:41:30 by marmulle          #+#    #+#             */
/*   Updated: 2022/11/04 16:05:43 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s1_len;

	if (!s1)
		return (NULL);
	if (!set || !(*set))
	{
		str = ft_strdup(s1);
		if (!str)
			return (NULL);
		return (str);
	}
	while (*s1 && ft_strchr(set, *s1))
		++s1;
	if (!(*s1))
		return (ft_strdup(""));
	s1_len = ft_strlen(s1);
	while (ft_strchr(set, s1[(--s1_len)]))
		;
	str = (char *)malloc(sizeof(char) * (s1_len + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 2);
	return (str);
}
