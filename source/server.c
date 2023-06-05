/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:12:05 by marmulle          #+#    #+#             */
/*   Updated: 2023/02/02 18:11:59 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*append_char(char *message, size_t message_len, char c)
{
	char	*output;

	output = malloc(sizeof(char) * (message_len + 2));
	if (!output)
	{
		free(message);
		exit(ft_printf("server - message allocation failed"));
	}
	ft_memcpy(output, message, message_len);
	output[message_len] = c;
	output[message_len + 1] = '\0';
	free(message);
	message = NULL;
	return (output);
}

void	handle_signal(int signum, siginfo_t *siginfo, void *ucontext)
{
	static char		byte = 0b00000000;
	static int		shift = 7;
	static char		*message = NULL;
	static size_t	message_len = 0;

	(void) ucontext;
	byte |= (signum - SIGUSR1) << shift--;
	if (shift < 0)
	{
		if (byte == 0b00000000)
		{
			write(1, message, message_len);
			message_len = 0;
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				ft_printf("server - cannot confirm message\n");
		}
		else
			message = append_char(message, message_len++, byte);
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
		pause();
	return (0);
}
