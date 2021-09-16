/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:14:52 by adelille          #+#    #+#             */
/*   Updated: 2021/09/16 19:05:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../libft/includes/libft.h"

typedef struct s_byte
{
	int		index;
	int		cpid;
}			t_byte;

int	ft_check_arg_client(int ac, char **av);

#endif
