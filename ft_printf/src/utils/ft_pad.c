/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:09:14 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/21 22:09:27 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_alloc_pad(unsigned char chr, size_t times)
{
	char	*pad;

	if (times)
	{
		pad = ft_calloc(times + 1, sizeof(unsigned char));
		if (pad)
		{
			ft_memset(pad, chr, times);
			return (pad);
		}
	}
	return (NULL);
}

char	*ft_pad_right(const char *str, unsigned char chr, size_t times)
{
	char	*pad;
	char	*newstr;

	pad = ft_alloc_pad(chr, times);
	if (pad)
	{
		newstr = ft_strjoin(str, pad);
		free(pad);
		if (newstr)
			return (newstr);
	}
	return (NULL);
}

char	*ft_pad_left(const char *str, unsigned char chr, size_t times)
{
	char	*pad;
	char	*newstr;

	pad = ft_alloc_pad(chr, times);
	if (pad)
	{
		newstr = ft_strjoin(pad, str);
		free(pad);
		if (newstr)
			return (newstr);
	}
	return (NULL);
}
