/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:40 by marmulle          #+#    #+#             */
/*   Updated: 2022/12/05 17:50:39 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_specifier(const char *fmt, va_list args, int *count)
{
	if (*fmt == '%')
		ft_print_char('%', count);
	else if (*fmt == 'c')
		ft_print_char(va_arg(args, int), count);
	else if (*fmt == 's')
		ft_print_str(va_arg(args, char *), count);
	else if (*fmt == 'i' || *fmt == 'd')
		ft_print_nbr(va_arg(args, int), count);
	else if (*fmt == 'u')
		ft_print_nbr(va_arg(args, unsigned int), count);
	else if (*fmt == 'x' || *fmt == 'X')
		ft_print_hex(va_arg(args, unsigned int), *fmt, count);
	else if (*fmt == 'p')
		ft_print_ptr(va_arg(args, uintptr_t), count);
	else
		ft_print_char(*fmt, count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			if (*fmt == '\0')
				return (count);
			ft_printf_specifier(fmt, args, &count);
		}
		else
			ft_print_char(*fmt, &count);
		if (*fmt)
			++fmt;
	}
	va_end(args);
	return (count);
}
