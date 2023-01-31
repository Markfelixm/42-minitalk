/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:47:04 by marmulle          #+#    #+#             */
/*   Updated: 2022/11/07 19:28:43 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_get_digits(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
		++digits;
	while (n)
	{
		n /= 10;
		++digits;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		digits;
	int		sign;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = n;
	digits = ft_get_digits(n);
	if (n < 0)
		n *= -1;
	number = ft_calloc(digits + 1, sizeof(char));
	if (!number)
		return (NULL);
	while (n)
	{
		number[--digits] = n % 10 + '0';
		n /= 10;
	}
	if (sign < 0)
		number[--digits] = '-';
	return (number);
}
