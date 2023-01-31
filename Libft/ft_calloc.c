/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:08:55 by marmulle          #+#    #+#             */
/*   Updated: 2022/11/11 16:04:50 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	product;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	product = count * size;
	ptr = malloc(product);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, product);
	return (ptr);
}
