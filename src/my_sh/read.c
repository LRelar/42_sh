/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:06:21 by mschimme          #+#    #+#             */
/*   Updated: 2019/09/13 15:46:32 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define READBUFSZ 9

void		ft_read(t_shellstate *shell)
{
	char	readbuff[READBUFSZ];

	ft_bzero((void *)readbuff, sizeof(readbuff));
int			debres;
	while(shell->startread)
	{
		// if (shell->show_prompt)
		// 	(shell->show_prompt)(&(shell->prompt));
		if ((debres = read(0, readbuff, READBUFSZ - 1)) == STD_ERR_C)
			break ;
		DEBintt("Bytes read", debres)
		DEBl("Key in NUM:", *(size_t *)(&readbuff[0]))
		*(size_t *)readbuff = 0;
		ft_putchar('\n');
	//	ft_proces_input(shell);
	}
}