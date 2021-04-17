/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfprime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 08:48:44 by mschimme          #+#    #+#             */
/*   Updated: 2019/08/24 08:58:48 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_end(void)
{
	printf("%c", '\n');
	return (0);
}

int			main(int argc, char **argv)
{
	int		i;
	int		k;
	if (argc != 2)
		return (ft_end());
	i = atoi(argv[1]);
	k = 2;
	while (i >= k)
	{
		// printf("k: %d\t i: %d\n", k, i);
		if (!(i % k))
		{
			printf("%d", k);
			if (k != i)
				printf("%c", '*');
			i /= k;
			k = 2;
			continue ;
		}
		k++;
	}
	return (ft_end());
}