/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:13:23 by adelille          #+#    #+#             */
/*   Updated: 2021/09/16 17:55:25 by adelille         ###   ########.fr       */
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
	struct sigaction	s_sig;

	if (ac != 3 || !ft_strlen(av[2]))
		return (1);
	ft_ps("Sent\t: ");
	ft_pn(ft_strlen(av[2]));
	ft_ps("\n");
	ft_ps("Received: ");
	s_sig.sa_handler = ft_sigaction;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, 0);
	sigaction(SIGUSR2, &s_sig, 0);
	ft_kill(ft_atoi(av[1]), av[2]);
	while (1)
		pause();
	return (0);
}
