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

volatile sig_atomic_t	g_isrunning = 1;

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

void	handle_sig(int signum, siginfo_t *siginfo, void *sigcontext)
{
	static char		c = 0;
	static int		i = 0;
	static pid_t	o_pid;

	o_pid = siginfo->si_pid;
	sigcontext = NULL;
	if (signum == SIGUSR1)
		c |= 1 << i;
	else if (signum == SIGUSR2)
		c &= ~(1 << i);
	if (i == 7)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
		usleep(100);
	}
	else
		++i;
}

/* -------------------------------------------------------------------------- */

void	init_sigvars_data(t_sigvars *vars)
{
	sigemptyset(&vars->sigs_mask);
	sigaddset(&vars->sigs_mask, SIGUSR1);
	sigaddset(&vars->sigs_mask, SIGUSR2);
	vars->act.sa_sigaction = handle_sig;
	vars->act.sa_mask = vars->sigs_mask;
	vars->act.sa_flags = SA_SIGINFO;
}

/* -------------------------------------------------------------------------- */

int	main(void)
{
	t_sigvars	vars;

	printf("%sThe Server's PID is:%s\t%s%d%s\n\n", MGN, NC, BLD, getpid(), NC);
	init_sigvars_data(&vars);
	sigaction(SIGUSR1, &vars.act, NULL);
	sigaction(SIGUSR2, &vars.act, NULL);
	while (1)
		;
	return (0);
}	

/* -------------------------------------------------------------------------- */
