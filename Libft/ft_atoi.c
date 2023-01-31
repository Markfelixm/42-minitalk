/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:05:09 by marmulle          #+#    #+#             */
/*   Updated: 2022/11/04 17:05:49 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	res;
	char	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t'
		|| *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		++str;
	if (*(str) == '-')
			sign = -1;
	if (*str == '+' || *str == '-')
		++str;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*(str++) - '0');
		if (res < 0 && sign == 1)
			return (-1);
		if (res < 0 && sign == -1)
			return (0);
	}
	return (sign * res);
}
