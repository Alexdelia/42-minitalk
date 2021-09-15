/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:13:23 by adelille          #+#    #+#             */
/*   Updated: 2021/09/15 16:20:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../libft/includes/libft.h"

int	main(int ac, char **av)
{
	ft_pn(ac);
	ft_ps("\n");
	ft_ps(av[0]);
	ft_ps("\n");
	return (0);
}
