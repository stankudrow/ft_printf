/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:22:14 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 01:22:14 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlist_map(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*newlst;
	t_dlist	*node;

	newlst = NULL;
	while (lst)
	{
		node = ft_dlist_new((*f)(lst->content));
		if (!node)
		{
			ft_dlist_clear(&newlst, del);
			return (NULL);
		}
		ft_dlist_add_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}
