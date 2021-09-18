/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:13:23 by adelille          #+#    #+#             */
/*   Updated: 2021/09/18 17:46:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_psc("Sent\n", BWHI);
}

static void	ft_send_byte(int c, int server_id)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c & (1 << i)) == 0)
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		usleep(200);
		--i;
	}
}

static void	ft_send_client_pid(int client_id, int server_id)
{
	char	buffer[65];
	int		i;

	i = 0;
	while (client_id)
	{
		buffer[i] = client_id % 10 + 48;
		client_id /= 10;
		i++;
	}
	while (i--)
		ft_send_byte(buffer[i], server_id);
	ft_send_byte(0, server_id);
}

int	main(int ac, char **av)
{
	int	i;
	int	server_id;
	int	client_id;

	if (ft_check_arg_client(ac, av) == 1)
		return (1);
	signal(SIGUSR1, ft_signal);
	client_id = getpid();
	server_id = ft_atoi(av[1]);
	ft_send_client_pid(client_id, server_id);
	i = 0;
	while (av[2][i])
		ft_send_byte(av[2][i++], server_id);
	ft_send_byte(0, server_id);
	return (0);
}
