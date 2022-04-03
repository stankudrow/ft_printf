/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:20:29 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 00:20:29 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_slist.h"

t_slist	*ft_slist_new(void *content)
{
	t_slist	*node;

	node = ft_calloc(1, sizeof(t_slist));
	if (node)
	{
		node->content = content;
		node->next = NULL;
	}
	return (node);
}
