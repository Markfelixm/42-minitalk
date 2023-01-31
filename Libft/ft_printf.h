/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:38:25 by marmulle          #+#    #+#             */
/*   Updated: 2023/01/31 11:41:15 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

// Main ft_printf
int		ft_printf(const char *fmt, ...);

// Print utilities
void	ft_print_char(char c, int *count);
void	ft_print_str(const char *s, int *count);
void	ft_print_nbr(long n, int *count);
void	ft_print_hex(uintptr_t n, char uppercase, int *count);
void	ft_print_ptr(uintptr_t ptr, int *count);

#endif
