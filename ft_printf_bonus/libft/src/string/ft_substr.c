/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:58:59 by mhorton           #+#    #+#             */
/*   Updated: 2022/02/23 21:42:46 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	max;

	max = -1;
	slen = ft_strlen(s);
	if (start < slen)
	{
		if (max - start < len)
			return (NULL);
		if (slen > (start + len))
			slen = start + len;
		slen -= start;
		sub = ft_calloc(slen + 1, sizeof(char));
		if (sub)
			ft_memmove(sub, s + start, slen);
	}
	else
		sub = ft_calloc(1, sizeof(char));
	return (sub);
}
// ft_strlcpy(sub, s + start, slen + 1); -> ft_memmove(sub, s + start, slen);