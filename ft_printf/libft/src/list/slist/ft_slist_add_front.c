/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:21:54 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 00:21:54 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

void	ft_slist_add_front(t_slist **lst, t_slist *node)
{
	t_slist	*last;

	if (*lst)
	{
		last = ft_slist_last(node);
		last->next = *lst;
	}
	*lst = node;
}
