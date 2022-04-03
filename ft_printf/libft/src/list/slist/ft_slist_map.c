/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:20:38 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 00:20:39 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

t_slist	*ft_slist_map(t_slist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_slist	*newlst;
	t_slist	*node;

	newlst = NULL;
	while (lst)
	{
		node = ft_slist_new((*f)(lst->content));
		if (!node)
		{
			ft_slist_clear(&newlst, del);
			return (NULL);
		}
		ft_slist_add_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}
