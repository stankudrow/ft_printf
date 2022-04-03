/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_popleft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:21:49 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 01:21:49 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlist_popleft(t_dlist **lst)
{
	t_dlist	*first;

	if (*lst)
	{
		first = *lst;
		*lst = (*lst)->next;
		first->prev = NULL;
		first->next = NULL;
		return (first);
	}
	return (NULL);
}
