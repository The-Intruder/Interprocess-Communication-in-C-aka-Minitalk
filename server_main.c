/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:35:31 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/10 20:31:08 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* -------------------------------------------------------------------------- */

void	p_pid(int pid)
{
	write(1, MGN, ft_strlen(MGN));
	write(1, "The Server's PID is:\t", 21);
	write(1, NC, ft_strlen(NC));
	write(1, BLD, ft_strlen(BLD));
	ft_putnbr_fd(pid, 1);
	write(1, NC, ft_strlen(NC));
	write(1, "\n\n", 2);
}

/* -------------------------------------------------------------------------- */

void	handle_sig(int signum, siginfo_t *siginfo, void *sigcontext)
{
	static t_uint	c = 0;
	static t_uint	i = 0;
	static int		o_pid;

	sigcontext = NULL;
	if (o_pid && o_pid != siginfo->si_pid)
	{
		c = 0;
		i = 0;
		write(1, "\n\n", 2);
	}
	o_pid = siginfo->si_pid;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		if (signum == SIGUSR1)
			c |= (1 << i);
		++i;
		if (i == 8)
		{
			write(1, &c, 1);
			if (c == 0)
				kill(o_pid, SIGUSR1);
			c = 0;
			i = 0;
		}
	}
}

/* -------------------------------------------------------------------------- */

int	main(void)
{
	t_sigaction	act;

	p_pid(getpid());
	act.sa_sigaction = handle_sig;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}

/* -------------------------------------------------------------------------- */
