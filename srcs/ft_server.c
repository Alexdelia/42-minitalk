/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:10:09 by adelille          #+#    #+#             */
/*   Updated: 2021/09/16 18:02:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_byte	g_byte;

static int	ft_process(int mode, int value)
{
	static int	index = 0;
	static char	c;
	char		ret;

	if (mode == 1)
	{
		if (index == 8)
		{
			ret = c;
			index = 0;
			c = 0;
			return (ret);
		}
		return (-1);
	}
	else if (value == 1)
		c |= (128 >> index);
	index++;
	return (c);
}

static void	ft_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_process(0, 0);
	else
		ft_process(0, 1);
	g_byte.index++;
}

static int	ft_process_client(void)
{
	int	pid;
	int	byte;

	pid = 0;
	while (1)
	{
		byte = ft_process(1, 0);
		if (byte == 0)
			break ;
		if (byte != -1)
			pid = pid * 10 + byte - '0';
	}
	while (1)
	{
		byte = ft_process(1, 0);
		if (byte == 0)
		{
			write(1, "\n", 1);
			break ;
		}
		if (byte != -1)
			write(1, &byte, 1);
	}
	kill(pid, SIGUSR1)
	return (pid);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
		return (ft_pserc("Server: No arguments needed\n", RED) * 0 + 1);
	ft_ps("Server PID [");
	ft_pn(getpid());
	ft_ps("]\n");
	signal(SIGUSR1, ft_signal);
	signal(SIGUSR2, ft_signal);
	while (1)
	{
		g_byte.cpid = 0;
		ft_process_client();
	}
	return (0);
}
