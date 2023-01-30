/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:43:25 by nradin            #+#    #+#             */
/*   Updated: 2023/01/30 19:52:32 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

t_temp_state	g_temp_state;

void	init_temp_state(void)
{
	g_temp_state.client_pid = 0;
	g_temp_state.i = 0;
	g_temp_state.prog_char = 0;
}

void	message_receive(int sig, siginfo_t *info, void *ucontext)
{
	int	bit;

	(void)ucontext;
	bit = sig - SIGUSR1;
	if (info->si_pid != g_temp_state.client_pid)
		init_temp_state();
	g_temp_state.prog_char = g_temp_state.prog_char << 1 | bit;
	g_temp_state.i++;
	if (g_temp_state.i == 8)
	{
		if (!g_temp_state.prog_char)
			kill(g_temp_state.client_pid, SIGUSR1);
		ft_putchar_fd(g_temp_state.prog_char, 1);
		init_temp_state();
	}
	g_temp_state.client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server's PID is: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &message_receive;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (0 == 0)
		usleep(1);
}
