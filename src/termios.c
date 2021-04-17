/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:23:32 by mschimme          #+#    #+#             */
/*   Updated: 2019/08/26 22:12:58 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define NDEBUG
#include "minishell.h"

uint8_t	ft_init_terminal(t_termios *termset, t_shellstate *shell)
{DEBfunc()
	if ((tcgetattr(STDIN_FILENO, &(termset[0])) == STD_ERR_C))
		return (ERR_TERMINIT);
	ft_memcpy(&termset[1], &termset[0], sizeof(t_termios));
	shell->termios_old = termset;
	shell->termios_new = termset + 1;
	shell->termios_new->c_lflag &= ~(ICANON);
	shell->termios_new->c_lflag &= ~(ECHO);
	shell->termios_new->c_cc[VMIN] = 1;
	shell->termios_new->c_cc[VTIME] = 0;
	if ((tcsetattr(STDIN_FILENO, TCSADRAIN, shell->termios_new) == STD_ERR_C))
		return (ERR_TERMINIT);
	return (FT_NOERR);
}
