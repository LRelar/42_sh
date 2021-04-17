/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:16:06 by mschimme          #+#    #+#             */
/*   Updated: 2019/06/13 19:14:02 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_stralloc(size_t size)
{
	char *pocket;

	if (!(pocket = (char *)malloc(size)))
		return (NULL);
	*pocket = '\0';
	*(pocket + size - 1) = '\0';
	return (pocket);
}
