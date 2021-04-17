/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishfuncs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:30:23 by mschimme          #+#    #+#             */
/*   Updated: 2019/09/13 15:39:40 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHFUNCS_H
# define MINISHFUNCS_H
# include "minishell.h"

uint8_t		ft_init_terminal(t_termios *termset, t_shellstate *shell);
void		ft_init_environ(char **envv, t_shellstate *shell);
void		ft_abort_process(t_shellstate *shell, t_errft_rout *errfunc);
uint8_t		ft_init_buffs(t_shellstate *shell);


/*
**	ERRFUNCS
*/
void		ft_finit_terminal(void);
void		ft_fmalloc(void);
void		ft_finit_prompt(void);
void		ft_finit_buffs(void);


/*
**	PROMPT Funcs
*/
void		ft_show_hostname(t_prompt *prompt);
void		ft_show_curdir(t_prompt *prompt);
void		ft_show_both(t_prompt *prompt);
void		ft_built_in_prompt(t_shellstate *shell, uint8_t flag);

/*
**	READ Funcs
*/
void		ft_read(t_shellstate *shell);

#endif
