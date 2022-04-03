/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorton <mhorton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:52:03 by mhorton           #+#    #+#             */
/*   Updated: 2022/02/20 12:52:03 by mhorton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ma;
	unsigned char		chr;

	ma = s;
	chr = c;
	while (n--)
		if (*ma++ == chr)
			return ((void *)--ma);
	return (NULL);
}
