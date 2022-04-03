/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:52:35 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/21 22:21:32 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	resolve_spec_di(t_spec *spec, int nbr)
{
	(void) spec;
	(void) nbr;
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

static char	*get_nbr(t_spec *spec, int nbr)
{
	char	*nbrstr;

	nbrstr = ft_itoa(nbr);
	if (nbrstr)
	{
		if (spec->flags->sign)
		{
			if (nbr > 0)
			{
				dfdfdf
			}
		}
	}
	return (NULL);
}

int	resolve_di(t_spec *spec, int nbr)
{
	char	*nbrstr;

	resolve_spec_di(spec, nbr);
	nbrstr = ft_itoa(nbr);
	if (!nbrstr)
		return (-1);
	nbrstr = add_sign(spec, nbrstr);
	if (!nbrstr)
		return (-1);
	nbrstr = add_padding(spec, nbrstr);
	if (!nbrstr)
		return (-1);
	spec->str = nbrstr;
	spec->len = ft_strlen(spec->str);
	return (spec->len);
}
