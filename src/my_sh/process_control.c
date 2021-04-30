/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:43:45 by mschimme          #+#    #+#             */
/*   Updated: 2019/09/17 14:20:28 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_abort_process(t_shellstate *shell, t_errft_rout *erfunc)
{DEBfunc()
	char	**bogey;

	bogey = shell->envv;
	if (shell->termios_old)
		tcsetattr(STDIN_FILENO, TCSANOW, shell->termios_old);
	if (bogey)
	{
		while (*bogey)
		{
			free(*bogey);
			bogey++;
		}
		free(shell->envv);
	}
	if (erfunc)
		erfunc();
}
