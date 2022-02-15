/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:53:31 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/14 14:19:10 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* -------------------------------------------------------------------------- */

static void	p_end_msg(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, GRN, ft_strlen(GRN));
		write(1, "\n\tMessage Sent Successfully\n\n", 30);
		write(1, NC, ft_strlen(NC));
	}
}

/* -------------------------------------------------------------------------- */

static void	p_err(char *error)
{
	ft_printf("%sERROR %s%s(%s)\tSomething's wrong, please try again.%s\n", \
		RED, NC, BLD, error, NC);
	exit(-1);
}

/* -------------------------------------------------------------------------- */

static int	ckeck_pid_arg(char *ascii_pid)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(ascii_pid);
	while (ft_isdigit(ascii_pid[i]))
		++i;
	if (i != str_len)
		return (-1);
	return (0);
}

/* -------------------------------------------------------------------------- */

static int	send_msg(int pid, char *msg)
{
	t_uint	i;
	t_uint	j;
	t_uchar	c;

	i = 0;
	while (i <= ft_strlen(msg))
	{
		c = msg[i++];
		j = 0;
		while (j < 8)
		{
			if(c & (1 << j++))
			{
				if (kill(pid, SIGUSR1) == -1)
					p_err("SIGUSR1 Failure");
			}
			else
			{
				if(kill(pid, SIGUSR2) == -1)
					p_err("SIGUSR2 Failure");
			}
			usleep(200);
		}
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_sigaction	act;

	if (argc != 3 || ckeck_pid_arg(argv[1]) != 0)
		return (p_err("Invalid Arguments"), -1);
	act.sa_handler = p_end_msg;
	sigaction(SIGUSR1, &act, NULL);
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}

/* -------------------------------------------------------------------------- */


