/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorton <mhorton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:58:42 by mhorton           #+#    #+#             */
/*   Updated: 2022/02/20 12:58:43 by mhorton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*cptr;
	unsigned char	chr;

	cptr = s;
	chr = c;
	while (*s)
	{
		if (*s == c)
			cptr = s;
		s++;
	}
	if (*cptr == chr)
		return ((char *)cptr);
	if (*s == chr)
		return ((char *)s);
	return (NULL);
}
