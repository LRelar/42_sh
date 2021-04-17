/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bitwizenot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:58:03 by mschimme          #+#    #+#             */
/*   Updated: 2019/08/23 11:57:31 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	int	i;
	int k;

	k = 14;
	DEBintt("Original", k)
	k = ~k;
	DEBintt("reversed", k); DEBend()
	i = 35;
	DEBintt("Original i", i)
	i &= k;
	DEBintt("modifyed i", i); DEBend()
	return (0);
}



int					set_istrip (int desc, int value)
{
	struct termios	settings;
	int				result;


	result = tcgetattr (desc, &settings);
	if (result < 0)
	{
		perror ("error in tcgetattr");
		return 0;
	}

	settings.c_iflag &= ~ISTRIP;
	if (value)
	settings.c_iflag |= ISTRIP;

	result = tcsetattr (desc, TCSANOW, &settings);
	if (result < 0)
	{
		perror ("error in tcsetattr");
		return 0;
	 }
	return 1;
}
