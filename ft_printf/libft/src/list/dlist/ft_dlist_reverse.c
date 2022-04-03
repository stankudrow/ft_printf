/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:21:43 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 01:21:43 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlist_reverse(t_dlist **lst)
{
	t_dlist	*new;
	t_dlist	*tmp;

	new = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->prev = NULL;
		tmp->next = NULL;
		ft_dlist_add_front(&new, tmp);
	}
	*lst = new;
}
