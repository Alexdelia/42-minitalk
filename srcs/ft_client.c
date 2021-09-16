/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:13:23 by adelille          #+#    #+#             */
/*   Updated: 2021/09/16 19:06:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_sigaction(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_pn(received);
		ft_ps("\n");
		exit(0);
	}
}

static void	ft_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	server_id;
	int	client_id;

	if (ft_check_arg_client(ac, av) == 1)
		return (1);
	signal(SIGUSR1, ft_signal);
	client_id = get_pid();
	server_id = ft_atoi(av[1]);
	i = 0;
	while (1)
		pause();
	return (0);
}
