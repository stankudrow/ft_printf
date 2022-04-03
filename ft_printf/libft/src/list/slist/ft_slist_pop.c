/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:20:16 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 00:20:17 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

t_slist	*ft_slist_pop(t_slist **lst)
{
	t_slist	*prev;
	t_slist	*last;

	last = NULL;
	if (*lst)
	{
		prev = NULL;
		last = *lst;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		if (prev == NULL)
			*lst = NULL;
		else
			prev->next = NULL;
	}
	return (last);
}
