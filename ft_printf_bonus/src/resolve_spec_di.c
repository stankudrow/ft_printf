/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_spec_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:13:06 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/13 12:28:21 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	resolve_spec_di(t_spec *spec, int nbr)
{
	if (spec->zero)
		spec->zfill = '0';
	if (spec->prec >= 0 || spec->minus || spec->sign)
	{
		spec->zero = False;
		spec->zfill = ' ';
	}
	if (spec->sign)
	{
		if (nbr < 0)
			spec->sfill = '-';
		else
			spec->sfill = '+';
	}
}

static char	*add_padding(t_spec *spec, char *str)
{
	int		len;
	char	*pad;
	char	*newstr;

	len = spec->width - spec->prec;
	if (len > 0)
	{
		pad = ft_calloc(len + 1, sizeof(char));
		if (pad)
		{
			ft_memset(pad, spec->zfill, len);
			if (spec->minus)
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

char	*resolve_di(t_spec *spec, int nbr, const char *base)
{
	char	*nbrstr;
	char	*newstr;

	resolve_spec_di(spec, nbr);
	nbrstr = ft_itoa_base(nbr, base);
	if (!nbrstr)
		return (NULL);
	newstr = ft_calloc(spec->prec + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, nbrstr, spec->prec);
	return (add_padding(spec, newstr));
}
