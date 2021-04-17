/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symb_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:20:57 by mschimme          #+#    #+#             */
/*   Updated: 2019/08/28 20:15:42 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dealstring(char *buff, int fd)
{DEBfunc()
	while (*buff)
	{
		if(ft_isalpha(*buff) || *buff == ' ' || *buff == ':' || *buff == '\n')
		{
			ft_putchar_fd(*buff, 1);
			ft_putchar_fd(*buff, fd);
		}
		else
		{
			dprintf(fd, "%zu ", *(size_t *)buff);
			dprintf(1, "%zu ", *(size_t *)buff);
		}
		buff++;
	}
}

int		main(void)
{
	t_readbuf		buffer;
	int				fd;
	t_termios		terms[2];
	t_shellstate	shell;
	int				counter;
	int				flag;
	
	flag = 1;
	ft_bzero(&shell, sizeof(t_shellstate));
	ft_init_terminal(&terms[0], &shell);
	fd = open("./symnums", O_CREAT | O_RDWR | O_APPEND);
	fchmod(fd, S_IRWXU);
	ft_bzero(&buffer, sizeof(t_readbuf));
	while (1)
	{
		counter = read(0, (void *)buffer.r_buf, 8);
		ft_dealstring(buffer.r_buf, fd);
		ft_bzero(buffer.r_buf, 8);
	}
}