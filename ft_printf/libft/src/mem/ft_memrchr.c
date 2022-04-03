/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:48:17 by stanislav         #+#    #+#             */
/*   Updated: 2022/02/23 19:48:18 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	const unsigned char	*ma;
	unsigned char		chr;

	ma = s + n;
	chr = c;
	while (n--)
		if (*ma-- == chr)
			return ((void *)++ma);
	return (NULL);
}
