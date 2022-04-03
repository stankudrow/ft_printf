/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:23:03 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 01:23:03 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlist_add_front(t_dlist **lst, t_dlist *node)
{
	t_dlist	*last;

	if (*lst)
	{
		last = ft_dlist_last(node);
		last->next = *lst;
		(*lst)->prev = last;
	}
	*lst = node;
}
