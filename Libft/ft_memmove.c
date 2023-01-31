/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:24:28 by marmulle          #+#    #+#             */
/*   Updated: 2022/11/11 16:44:59 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!len)
		return (dst);
	i = 0;
	if (!dst && !src && len)
		return (NULL);
	if (dst <= src)
	{
		while (len-- > 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			++i;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
