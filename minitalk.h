/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:18:11 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/09 21:02:39 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* --------------------------- Included Libraries --------------------------- */
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libs/libft/libft.h"
# include "libs/get_next_line/get_next_line.h"

/* --------------------------------- Macros --------------------------------- */
# define BLD "\033[1m"
# define NC "\033[31;0m"
# define RED "\033[0;31;1m"
# define YEL "\033[0;33;1m"
# define GRA "\033[0;37;1m"
# define CYN "\033[0;36;1m"
# define GRN "\033[0;32;1m"
# define MGN "\033[0;35;1m"
# define BLU "\033[0;34;1m"

/* -------------------------------- Typedef's ------------------------------- */
typedef struct sigaction	t_sigaction;

typedef struct s_sigvars {
	t_sigaction	act;
	t_sigaction	oact;
	sigset_t	sigs_mask;
}	t_sigvars;

/* -------------------------------- Prototypes ------------------------------ */

#endif
