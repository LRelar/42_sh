/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:06:32 by mschimme          #+#    #+#             */
/*   Updated: 2019/08/27 18:08:09 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define NDEBUG
#include "minishell.h"

int				main(int argc, char **argv, char **envv)
{DEBfunc()
	t_termios		termset[2];
	t_shellstate	shell;
	ft_bzero(&shell, sizeof(shell));
	if (ft_init_terminal(termset, &shell))
		ft_abort_process(&shell, &ft_finit_terminal);
	ft_init_environ(envv, &shell);
	shell.startread = 1;
	// ft_init_sighandling(&shell);
	ft_read(&shell);
	return (0);
}
