/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:10:09 by adelille          #+#    #+#             */
/*   Updated: 2021/09/16 17:32:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../libft/includes/libft.h"

static void	ft_sigaction(int sig, siginfo_t *siginfo, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = siginfo->si_pid;
	c |= (sig == SIGUSR2); // bitwise inclusive OR assignement
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1; // bitwise left shift assignement
}

int	main(int ac, char **av)
{
	// check av 
	ft_ps("Server PID [");
	ft_pn(getpid());
	ft_ps("]\n");
	signal(SIGUSR1, ft_signal);
	signal(SIGUSR2, ft_signal);
	while (1)
	{
		ft_process_client();
	}
	return (0);
}
