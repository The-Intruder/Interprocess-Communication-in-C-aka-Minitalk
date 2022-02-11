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

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

void	handle_sig(int signum, siginfo_t *, void *)
{
}

/* -------------------------------------------------------------------------- */

void	init_sigvars_data(t_sigvars *vars)
{
	sigemptyset(&vars->sigs_mask);
	sigaddset(&vars->sigs_mask, SIGUSR1);
	sigaddset(&vars->sigs_mask, SIGUSR2);
	vars->act.sa_handler = handle_sig;
	vars->act.sa_sigaction = handle_sig;
	vars->act.sa_mask = vars->sigs_mask;
	vars->act.sa_flags = SA_SIGINFO;
	vars->sigact_ret_vl = sigaction(SIGUSR1, &vars->act, &vars->oact);
}

/* -------------------------------------------------------------------------- */

int	main(void)
{
	t_sigvars	vars;

	printf("%sThe Server's PID is:%s\t%s%d%s\n", MGN, NC, BLD, getpid(), NC);
	init_sigvars_data(&vars);
	return (0);
}	

/* -------------------------------------------------------------------------- */
