/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:12:02 by marmulle          #+#    #+#             */
/*   Updated: 2023/02/02 18:17:45 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handle_confirmation(int signum)
{
	(void) signum;
	exit(ft_printf("client - message confirmed\n"));
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
			usleep(96);
		}
		cursor++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	size_t	message_len;

	if (signal(SIGUSR2, handle_confirmation) == SIG_ERR)
		return (ft_printf("client - signal SIGUSR2 error\n"));
	if (argc != 3)
		return (ft_printf("client - invalid arguments\n"));
	message_len = ft_strlen(argv[2]);
	if (!send_message(ft_atoi(argv[1]), argv[2], message_len))
		return (ft_printf("client - send error\n"));
	if (sleep(message_len + 1) == 0)
		return (ft_printf("client - confirmation timed out\n"));
}
