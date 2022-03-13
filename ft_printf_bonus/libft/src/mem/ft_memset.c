/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorton <mhorton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:52:43 by mhorton           #+#    #+#             */
/*   Updated: 2022/02/20 12:52:44 by mhorton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ma;
	unsigned char	chr;

	ma = s;
	chr = c;
	while (n--)
		*ma++ = chr;
	return (s);
}
