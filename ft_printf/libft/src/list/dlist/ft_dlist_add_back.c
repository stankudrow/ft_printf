/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:23:08 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 01:23:08 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlist_add_back(t_dlist **lst, t_dlist *node)
{
	t_dlist	*last;

	if (*lst)
	{
		last = ft_dlist_last(*lst);
		last->next = node;
		node->prev = last;
	}
	else
		*lst = node;
}
