/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:17:36 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/21 23:17:36 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_is_valid_base(const char *base)
{
	size_t	blen;
	size_t	bci;
	size_t	bcj;

	blen = ft_strlen(base);
	if (blen < 2 || blen > 36)
		return (false);
	bci = 0;
	while (bci < blen)
	{
		if (!(base[bci] >= '0' && base[bci] <= '9') && \
			!(base[bci] >= 'A' && base[bci] <= 'Z') && \
			!(base[bci] >= 'a' && base[bci] <= 'z'))
			return (false);
		bcj = 0;
		while (bcj < bci)
		{
			if (base[bcj] == base[bci])
				return (false);
			bcj++;
		}
		bci++;
	}
	return (true);
}
