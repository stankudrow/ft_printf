/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_popleft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:20:06 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 00:20:06 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

t_slist	*ft_slist_popleft(t_slist **lst)
{
	t_slist	*first;

	if (*lst)
	{
		first = *lst;
		*lst = first->next;
		first->next = NULL;
		return (first);
	}
	return (NULL);
}
