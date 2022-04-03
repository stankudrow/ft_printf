/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:13:06 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/17 22:52:20 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	resolve_spec_s(t_spec *spec, char **tmpstr)
{
	if (spec->flags->minus)
	{
		spec->flags->zero = False;
		spec->flags->zfill = ' ';
	}
	if (!*tmpstr)
	{
		*tmpstr = NULLSTR;
		if (spec->widprec->prec > 0)
			spec->widprec->prec = 0;
	}
	if (!spec->widprec->dot || (spec->widprec->prec < 0))
		spec->widprec->prec = ft_strlen(*tmpstr);
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

int	resolve_s(t_spec *spec, char *str)
{
	char	*tmp;
	char	*newstr;

	tmp = str;
	resolve_spec_s(spec, &tmp);
	newstr = ft_calloc(spec->widprec->prec + 1, sizeof(char));
	if (!newstr)
		return (-1);
	ft_memcpy(newstr, tmp, spec->widprec->prec);
	tmp = add_padding(spec, newstr);
	if (!tmp)
		return (-1);
	spec->str = tmp;
	spec->len = ft_strlen(spec->str);
	return (spec->len);
}
