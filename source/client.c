/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:12:02 by marmulle          #+#    #+#             */
/*   Updated: 2023/01/31 14:12:00 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handle_confirmation(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void) signum;
	(void) siginfo; // TODO: check that PIDs match
	(void) ucontext;
	ft_printf("client - message confirmed\n");
	exit(0);
}

bool	send_message(int pid, char *message, size_t message_len)
{
	size_t	cursor;
	int		shift;
	int		signal;

	cursor = 0;
	while (cursor < message_len + 1)
	{
		shift = -1;
		while (++shift < 8)
		{
			signal = SIGUSR1;
			if (message[cursor] << shift & 0b10000000)
				signal = SIGUSR2;
			if (kill(pid, signal) == -1)
				return (false);
			usleep(128);
		}
		cursor++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	size_t				message_len;

	sa.sa_sigaction = handle_confirmation;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR2, &sa, NULL))
		return (ft_printf("client - sigaction SIGUSR2 error\n"));
	if (argc != 3)
		return (ft_printf("client - invalid arguments\n"));
	message_len = ft_strlen(argv[2]);
	if (!send_message(ft_atoi(argv[1]), argv[2], message_len))
		return (ft_printf("client - send error\n"));
	if (sleep(message_len + 1) == 0)
		return (ft_printf("client - confirmation timed out\n"));
}