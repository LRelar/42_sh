/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishdefines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:32:03 by mschimme          #+#    #+#             */
/*   Updated: 2019/09/13 16:07:52 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHDEFINES_H
# define MINISHDEFINES_H
# include "minishell.h"

typedef struct	termios t_termios;
typedef struct	s_prompt t_prompt;

typedef void	t_dprompt_rout(t_prompt *prompt);

typedef struct		s_readbuf
{
	char			r_buf[9];
	uint8_t			rem;
}					t_readbuf;

typedef struct		s_combuff
{
	char				*buff;
	size_t				size;
	char				*curpos;
	char				*curselect;
}					t_combuff;

typedef struct		s_showbuf
{
	char				*buff;
	size_t				size;
	char				*curpos;
	char				*curselect;
	struct s_showbuf	*previnp;
	struct s_showbuf	*nextinp;
}					t_showbuf;

typedef struct		s_prompt
{
	char			*hostname;
	char			foldsym[8];
	char			*curdname;
	char			ending[5];
	char			subpr[4];
}					t_prompt;

typedef struct		s_shellstate
{
	char			**envv;
	t_termios		*termios_old;
	t_termios		*termios_new;
	uint8_t			startread;
	t_prompt		prompt;
	t_readbuf		*frontbuf;
	t_dprompt_rout	*show_prompt;
	t_readbuf		readbuf;
	t_combuff		*curcmd;
	t_showbuf		*curinp;
}					t_shellstate;



typedef void	t_errft_rout(void);
typedef char	*t_scanenv_rout(char *envvname, char **envv);
typedef void	*t_disp_prompt(t_prompt *prompt);

/*
**								ERRCODES
*/
# define FT_NOERR				0
# define STD_ERR_C				-1
# define ERR_TERMINIT			1
# define ERR_INIT_PROMPT		2
# define ERR_KERN				3
# define ERR_INIT_BUFFS			4
# define ERR_MALLOC				69
# define ERR_OPEN				70
# define DIRSYM -2104254480
# define MACSYM -1516855312

/*
**					SYMBOLS, WIDE SYMBOS and SYMBOL SEQUENCES
*/

# define S_NULL 0x00
# define S_SOH 0x01
# define S_STX 0x02
# define S_ETX 0x03
# define S_EOT 0x04
# define S_ENQ 0x05
# define S_ACK 0x06
# define S_BEL 0x07
# define S_BS 0x08
# define S_HT 0x09
# define S_NL 0x0a
# define S_VT 0x0b
# define S_NP 0x0c
# define S_CR 0x0d
# define S_SO 0x0e
# define S_SI 0x0f
# define S_DLE 0x10
# define S_DC1 0x11
# define S_DC2 0x12
# define S_DC3 0x13
# define S_DC4 0x14
# define S_NAK 0x15
# define S_SYN 0x16
# define S_ETB 0x17
# define S_CAN 0x18
# define S_EM 0x19
# define S_SUB 0x1a
# define S_ESC 0x1b
# define S_FS 0x1c
# define S_GS 0x1d
# define S_RS 0x1e
# define S_US 0x1f
# define S_SP 0x20
# define S_DEL 0x7f


/*
**					Keys in Numbers:
**	K_RET == Enter key;
**	K_BS == Backspace;
**	K_DEL == Del Key;
*/
# define K_UP		0x425B1BUL
# define K_DOWN		0x425B1BUL
# define K_LEFT		0x445B1BUL
# define K_RIGHT	0x435B1BUL

# define K_RET		0xAUL
# define K_BS		0x7FUL
# define K_DEL		0x7E335B1BUL



#endif