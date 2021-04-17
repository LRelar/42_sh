/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strupdate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:04:03 by mschimme          #+#    #+#             */
/*   Updated: 2019/08/23 11:57:24 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include <signal.h>
#include "minishell.h"
typedef void (*sig_t) (int);
typedef struct			s_cmd_buff
{
	char				*buffst;
	char				*buffend;
	char				*boff_t;
	size_t				b_size;
}						t_cmd_buff;

static void		ft_reg_input(t_cmd_buff *shit, char *lilbuf)
{
	if (*lilbuf)
	{
		*(shit->buffst) = *lilbuf;
		shit->buffst++;
		ft_putchar(*lilbuf);
	}
}


int				main(int argc, char **argv)
{
	t_cmd_buff shit;




	ft_bzero(&shit, sizeof(shit));
	shit.buffst = ft_memalloc(512);
	shit.b_size = 512;
	shit.buffend = shit.buffst + 512 - 1;
	shit.boff_t = shit.buffst;
	char lol[9];
	lol[8] = '0';
	*(size_t *)lol = 0;
	while (1)
	{
		if ((read(0, &lol[0], 8)) == -1)
			break;
		ft_reg_input(&shit, &lol[0]);
		*(size_t *)lol = 0;

	}
	return (0);
}
