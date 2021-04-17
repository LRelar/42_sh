/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:47:51 by mschimme          #+#    #+#             */
/*   Updated: 2019/09/13 13:50:55 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline static int	ft_count_envars(char **envv)
{DEBfunc()
	int				counter;

	counter = 1;
	while (*envv)
	{
		counter++;
		envv++;
	}
	return(counter);
}

inline static	uint8_t	ft_get_pc_name(t_prompt *prompt)
{DEBfunc()

	size_t		buffsize;
	char		*buff;

	buff = NULL;
	buffsize = 0;
	if (sysctlbyname("kern.hostname", buff, &buffsize, 0, 0) == STD_ERR_C)
		return (ERR_KERN);
	if (!(buff = (char *)ft_memalloc(buffsize * sizeof(char))))
		return (ERR_MALLOC);
	if (sysctlbyname("kern.hostname", buff, &buffsize, 0, 0) == STD_ERR_C)
		return (ERR_KERN);
	if (!(prompt->hostname = (char *)malloc((buffsize + 7) * sizeof(char))))
		return (ERR_MALLOC);
	ft_memcpy((void *)prompt->hostname, (CV *)"🖥 : ", 7);
	ft_memcpy((void *)prompt->hostname + 7, buff, buffsize);
	free(buff);
	return (FT_NOERR);
}

inline static uint8_t	ft_init_prompt(t_prompt *prompt)
{DEBfunc()
	char		*path;
	char		*ptr;
	uint8_t		errflag;

	path = NULL;
	errflag = ERR_INIT_PROMPT;
	if ((path = getcwd(path, 0)))
	{
		errflag = FT_NOERR;
		ft_memcpy((void *)prompt->foldsym, (CV *)" 📂: ", 8);
		ft_memcpy((void *)prompt->ending, (CV *)" $> ", 5);
		ft_memcpy((void *)prompt->subpr, (CV *)" > ", 4);
		ptr = ft_strrchr(path, '/');
		if (!(prompt->curdname = ft_strdup(ft_strlen(ptr) == 1 ? ptr : ptr + 1)))
			errflag = ERR_MALLOC;
		if (ft_get_pc_name(prompt))
			errflag = ERR_INIT_PROMPT;
		free(path);
	}
	return(errflag);
}

uint8_t					ft_init_buffs(t_shellstate *shell)
{DEBfunc()
	if (!(shell->curcmd))
	{
		if (!(shell->curcmd = (t_combuff *)ft_memalloc(sizeof(t_combuff))))
			return(ERR_INIT_BUFFS);
		shell->curcmd->size = 256;
		if (!(shell->curcmd->buff = (char *)ft_memalloc(sizeof(char) * \
														shell->curcmd->size)))
			return(ERR_INIT_BUFFS);
		shell->curcmd->curpos = shell->curcmd->buff;
	}
	if (!(shell->curinp))
	{
		if (!(shell->curinp = (t_showbuf *)ft_memalloc(sizeof(t_showbuf))))
			return(ERR_INIT_BUFFS);
		shell->curinp->size = 256;
		if (!(shell->curinp->buff = (char *)ft_memalloc(sizeof(char) * \
														shell->curinp->size)))
			return(ERR_INIT_BUFFS);
		shell->curinp->curpos = shell->curinp->buff;
	}
	else
		return (ERR_INIT_BUFFS);
	return (FT_NOERR);
}

void	ft_init_environ(char **envv, t_shellstate *shell)
{DEBfunc()
	int	i;

	i = 0;
	if (!(shell->envv = (char **)ft_memalloc(ft_count_envars(envv) * sizeof(char *))))
		ft_abort_process(shell, &ft_fmalloc);
	while (envv[i])
	{
		if (!(shell->envv[i] = ft_strdup(envv[i])))
			ft_abort_process(shell, &ft_fmalloc);
		i++;
	}
	if(ft_init_prompt(&(shell->prompt)))
		ft_abort_process(shell, &ft_finit_prompt);
	ft_built_in_prompt(shell, 0);
	if (ft_init_buffs(shell))
		ft_abort_process(shell, &ft_finit_buffs);
}