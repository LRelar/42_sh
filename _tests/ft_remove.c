/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 09:07:01 by mschimme          #+#    #+#             */
/*   Updated: 2019/08/24 09:25:47 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int ascending(int a, int b)
{
	return (a <= b);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*i;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	i = *begin_list;
	while (i && i->next)
	{
		if (cmp(i->next->data, data_ref) == 0)
		{
			tmp = i->next;
			i->next = tmp->next;
			free(tmp);
		}
		if (i->next)
			i = i->next;
	}
}

int		main(void)
{
	t_list one;
	t_list	two;
	t_list	tri;
	t_list	qua;
	t_list	qui;
	t_list	sex;
	t_list	sep;
	t_list	oct;
	one.data = 1; one.next = &two;
	two.data = 2; two.next = &tri;
	tri.data = 3; tri.next = &qua;
	qua.data = 4; qua.next = &qui;
	qui.data = 5; qui.next = &sex;
	sex.data = 6; sex.next = &sep;
	sep.data = 7; sep.next = &oct;
	oct.data = 8; oct.next = (void *)0;
	
}