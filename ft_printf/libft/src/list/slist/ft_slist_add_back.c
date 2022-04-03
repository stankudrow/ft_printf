/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:22:07 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 00:22:07 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

void	ft_slist_add_back(t_slist **lst, t_slist *node)
{
	t_slist	*last;

	if (*lst)
	{
		last = ft_slist_last(*lst);
		last->next = node;
	}
	else
		*lst = node;
}
