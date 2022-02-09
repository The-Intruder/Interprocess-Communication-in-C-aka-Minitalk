/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:35:31 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/09 21:02:43 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

int	main(void)
{
	int			server_pid;
	t_sigaction	sa;

	server_pid = getpid();
	printf("%sThe Server's PID is:%s\t%s%d%s\n", MGN, NC, BLD, server_pid, NC);
	sa.sa_handler = confirm_sig();
	return (0);
}	

/* -------------------------------------------------------------------------- */
