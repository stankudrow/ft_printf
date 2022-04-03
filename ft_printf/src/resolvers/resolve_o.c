/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:52:35 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/17 23:06:18 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	resolve_spec_o(t_spec *spec, UI unbr)
{
	(void) spec;
	(void) unbr;
}

static char	*add_padding(t_spec *spec, char *str)
{
	int		len;
	char	*pad;
	char	*newstr;

	len = spec->widprec->width - spec->widprec->prec;
	if (len > 0)
	{
		pad = ft_calloc(len + 1, sizeof(char));
		if (pad)
		{
			ft_memset(pad, spec->flags->zfill, len);
			if (spec->flags->minus)
				newstr = ft_strjoin(str, pad);
			else
				newstr = ft_strjoin(pad, str);
			free(str);
			free(pad);
			return (newstr);
		}
	}
	return (str);
}

static char	*add_sign(t_spec *spec, const char *unbr)
{
	(void) spec;
	(void) unbr;
	return ((char *)unbr);
}

int	resolve_o(t_spec *spec, UI unbr)
{
	char	*unbrstr;

	resolve_spec_o(spec, unbr);
	unbrstr = ft_uitoa_base(unbr, OB);
	if (!unbrstr)
		return (-1);
	unbrstr = add_sign(spec, unbrstr);
	if (!unbrstr)
		return (-1);
	unbrstr = add_padding(spec, unbrstr);
	if (!unbrstr)
		return (-1);
	spec->str = unbrstr;
	spec->len = ft_strlen(spec->str);
	return (spec->len);
}
