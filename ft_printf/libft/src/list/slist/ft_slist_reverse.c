/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:19:55 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 00:19:55 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

void	ft_slist_reverse(t_slist **lst)
{
	t_slist	*new;
	t_slist	*tmp;

	new = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = NULL;
		ft_slist_add_front(&new, tmp);
	}
	*lst = new;
}
