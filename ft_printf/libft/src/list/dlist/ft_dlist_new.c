/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:22:02 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 01:22:02 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlist_new(void *content)
{
	t_dlist	*node;

	node = ft_calloc(1, sizeof(t_dlist));
	if (node)
	{
		node->content = content;
		node->prev = NULL;
		node->next = NULL;
	}
	return (node);
}
