/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:22:47 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 01:22:48 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlist_clear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*node;

	while (*lst)
	{
		node = *lst;
		*lst = (*lst)->next;
		ft_dlist_delone(node, del);
		node = NULL;
	}
	*lst = NULL;
}
