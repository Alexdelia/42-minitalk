/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_client.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:05:07 by adelille          #+#    #+#             */
/*   Updated: 2021/09/16 18:48:15 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_check_digits(char *str)
{

}

int	check_arg_client(int ac, char **av)
{
	long	pid;

	if (ac < 3)
		return ((ft_pserc("Error: Too few arguments\n", RED)
				+ ft_pserc("Need PID of server then the message\n", RED))
			* 0 + 1);
	pid = ft_atol(av[1]);
	if (ft_check_digits(av[1] == FALSE || pid > INT_MAX || pid < 0)
		return (ft_pserc("Error: Server PID invalid\n") * 0 + 1);
	return (0);
}
