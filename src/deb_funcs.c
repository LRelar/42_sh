/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 20:44:36 by mschimme          #+#    #+#             */
/*   Updated: 2019/08/25 21:07:11 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deblib.h"
#include <stdlib.h>

/*
**			DEBug functions required to implement my_assert
*/

char	ft_myssert(const char *func, char *file, int line, char *expr)
{DEBfunc()
	printf("Assertion \033[1;36m%s\033[0m failed: file: \033[0;33m%s\033[0m, function: \033[0;33m%s\033[0m, line: \033[0;31m%d\033[0m \n", expr, file, func, line);
	exit(0);
}