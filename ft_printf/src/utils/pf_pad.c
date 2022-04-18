/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:45:46 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/18 22:45:46 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*pf_alloc_pad(unsigned char chr, size_t times)
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

char	*pf_pad_left(const char *str, unsigned char chr, size_t times)
{
	char	*pad;
	char	*newstr;

	pad = pf_alloc_pad(chr, times);
	if (pad)
	{
		newstr = ft_strjoin(pad, str);
		free(pad);
		if (newstr)
			return (newstr);
	}
	newstr = ft_strdup(str);
	if (newstr)
		return (newstr);
	return (NULL);
}

t_status	pf_pad_spec_left(t_spec *spec, unsigned char chr, size_t times)
{
	char	*str;

	if (!spec->str)
		return (FAIL);
	str = pf_pad_left(spec->str, chr, times);
	if (!str)
		return (ERROR);
	free(spec->str);
	spec->str = str;
	spec->len = ft_strlen(str);
	return (OK);
}

char	*pf_pad_right(const char *str, unsigned char chr, size_t times)
{
	char	*pad;
	char	*newstr;

	pad = pf_alloc_pad(chr, times);
	if (pad)
	{
		newstr = ft_strjoin(str, pad);
		free(pad);
		if (newstr)
			return (newstr);
	}
	newstr = ft_strdup(str);
	if (newstr)
		return (newstr);
	return (NULL);
}

t_status	pf_pad_spec_right(t_spec *spec, unsigned char chr, size_t times)
{
	char	*str;

	if (!spec->str)
		return (FAIL);
	str = pf_pad_right(spec->str, chr, times);
	if (!str)
		return (ERROR);
	free(spec->str);
	spec->str = str;
	spec->len = ft_strlen(str);
	return (OK);
}
