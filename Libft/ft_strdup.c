/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:26:08 by marmulle          #+#    #+#             */
/*   Updated: 2022/11/04 14:34:31 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen(s1);
	str = (char *)malloc(s_len + 1);
	if (!str)
		return (NULL);
	while (*s1)
		*(str++) = *(s1++);
	*str = '\0';
	return (str - s_len);
}
