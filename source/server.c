/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:12:05 by marmulle          #+#    #+#             */
/*   Updated: 2023/01/31 14:12:04 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handle_signal(int signum, siginfo_t *siginfo, void *ucontext)
{
	static char	byte = 0b00000000;
	static int	shift = 7;

	(void) ucontext;
	byte |= (signum - SIGUSR1) << shift--;
	if (shift < 0)
	{
		if (byte == 0b00000000)
		{
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				ft_printf("server - cannot confirm message\n");
		}
		else
			write(1, &byte, 1);
		shift = 7;
		byte = 0b00000000;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL))
		return (ft_printf("server - sigaction SIGUSR1 error\n"));
	if (sigaction(SIGUSR2, &sa, NULL))
		return (ft_printf("server - sigaction SIGUSR2 error\n"));
	ft_printf("server - %d\n", getpid());
	while (1)
		;
	return (0);
}