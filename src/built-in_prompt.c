/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:21:17 by mschimme          #+#    #+#             */
/*   Updated: 2019/08/27 12:03:57 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void		ft_show_hostname(t_prompt *prompt)
{
	ft_putstr((CC *)prompt->hostname);
	ft_putstr((CC *)prompt->ending);
}

void		ft_show_curdir(t_prompt *prompt)
{
	ft_putstr((CC *)prompt->foldsym);
	ft_putstr((CC *)prompt->curdname);
	ft_putstr((CC *)prompt->ending);
}

void		ft_show_both(t_prompt *prompt)
{
	ft_putstr((CC *)prompt->hostname);
	ft_putstr((CC *)prompt->foldsym);
	ft_putstr((CC *)prompt->curdname);
	ft_putstr((CC *)prompt->ending);
}

void		ft_built_in_prompt(t_shellstate *shell, uint8_t flag)
{
	if (flag == 0)
		shell->show_prompt = &ft_show_hostname;
	else if (flag == 1)
		shell->show_prompt = &ft_show_curdir;
	else if (flag == 2)
		shell->show_prompt = &ft_show_both;
}