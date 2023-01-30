/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:43:23 by nradin            #+#    #+#             */
/*   Updated: 2023/01/30 19:49:42 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/client.h"

int	msg;

void	wrong_pid(void)
{
	ft_putstr_fd("Whong PID of server", 2);
	exit(0);
}

void	byte_send(char byte, int pid)
{
	int	i;
	int	kill_res;

	kill_res = 0;
	i = 7;
	while (i >= 0)
	{
		if (byte >> i & 1)
			kill_res = kill(pid, SIGUSR2);
		else
			kill_res = kill(pid, SIGUSR1);
		if (kill_res == -1)
			wrong_pid();
		usleep(100);
		i--;
	}
}

void	message_send(char *msg, int pid)
{
	while (*msg)
	{
		byte_send(*msg, pid);
		msg++;
	}
	byte_send(0, pid);
}

void	message_receive(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message from server was received!\n");
	msg = 1;
}

int	main(int argc, char *argv[])
{
	int	pid;

	msg = 0;
	signal(SIGUSR1, message_receive);
	if (argc != 3)
	{
		ft_putstr_fd("Wrong amount of arguments", 2);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (!argv[2][0])
		ft_putstr_fd("Message is empty", 2);
	message_send(argv[2], pid);
	if (msg == 0)
		sleep(INT_MAX);
	return (0);
}
