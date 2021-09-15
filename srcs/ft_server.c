/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:10:09 by adelille          #+#    #+#             */
/*   Updated: 2021/09/15 16:33:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../libft/includes/libft.h"

static void	ft_sigaction(int sig, siginfo_t *siginfo, void *context)
{

}

int	main(void)
{
	struct sigaction	s_sig; // man sigaction: https://man7.org/linux/man-pages/man2/sigaction.2.html

	ft_ps("Server PID: ");
	ft_pn(getpid());
	ft_ps("\n");
	s_sig.sa_sigaction = ft_sigaction;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, 0);
	sigaction(SIGUSR2, &s_sig, 0);
	while (1);
		pause();
	return (0);
}