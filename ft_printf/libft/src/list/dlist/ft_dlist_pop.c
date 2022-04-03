/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:21:56 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 10:25:28 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlist_pop(t_dlist **lst)
{
	t_dlist	*last;

	if (*lst)
	{
		last = ft_dlist_last(*lst);
		if (last->prev)
			last->prev->next = NULL;
		else
			*lst = NULL;
		last->prev = NULL;
		return (last);
	}
	return (NULL);
}
