/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:32:00 by marmulle          #+#    #+#             */
/*   Updated: 2022/12/01 16:48:18 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, int *count)
{
	(*count)++;
	write(1, &c, 1);
}

void	ft_print_str(const char *s, int *count)
{
	size_t	len;

	if (!s)
	{
		*count += 6;
		write(1, "(null)", 6);
		return ;
	}
	len = 0;
	while (*s)
	{
		++s;
		++len;
	}
	s -= len;
	*count += len;
	write(1, s, len);
}

void	ft_print_nbr(long n, int *count)
{
	if (n < 0)
	{
		ft_print_char('-', count);
		ft_print_nbr(-n, count);
	}
	else if (n > 9)
	{
		ft_print_nbr(n / 10, count);
		ft_print_nbr(n % 10, count);
	}
	else
		ft_print_char(n + '0', count);
}

void	ft_print_hex(uintptr_t n, char uppercase, int *count)
{
	unsigned long	mod;

	if (n == 0)
	{
		ft_print_char('0', count);
		return ;
	}
	if (n)
	{
		if (n / 16 > 0)
			ft_print_hex(n / 16, uppercase, count);
		mod = n % 16;
		if (mod < 10)
			ft_print_char(mod + '0', count);
		if (mod > 9)
		{
			if (uppercase == 'X')
				ft_print_char(mod + 'A' - 10, count);
			else
				ft_print_char(mod + 'a' - 10, count);
		}
	}
}

void	ft_print_ptr(uintptr_t ptr, int *count)
{
	ft_print_str("0x", count);
	if (!ptr)
		ft_print_char('0', count);
	else
		ft_print_hex(ptr, 'x', count);
}
