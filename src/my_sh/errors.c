/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:59:03 by mschimme          #+#    #+#             */
/*   Updated: 2019/08/28 12:14:21 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_finit_terminal(void)
{
	ft_putstr_fd("Minishell: failed to manage terminal device file.\n", 2);
}
void	ft_fmalloc(void)
{
	ft_putstr_fd("Minishell: failed to allocate memory.\n", 2);
}

void	ft_finit_prompt(void)
{
	ft_putstr_fd("Minishell: failed to allocate memory initiating \
														prompt struct.\n", 2);
}

void	ft_finit_buffs(void)
{
	ft_putstr_fd("Minishell: failed to allocate memory initiating \
														buffers structs.\n", 2);
}