/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:42:59 by mschimme          #+#    #+#             */
/*   Updated: 2019/08/28 19:30:34 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_check_stoporder(t_shellstate *shell, char *rbuff)
{
	if (*rbuff == S_EOT)
		ft_abort_process(shell, NULL);
}

void		ft_proces_input(t_shellstate *shell, char *r_buff)
{
	ft_check_stoporder(shell, r_buff);
	
}
