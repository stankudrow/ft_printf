/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_spec_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:13:06 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/13 14:27:01 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	resolve_spec_s(t_spec *spec, char **tmpstr)
{
	if (spec->minus)
	{
		spec->zero = False;
		spec->zfill = ' ';
	}
	if (!*tmpstr)
	{
		*tmpstr = NULLSTR;
		if (spec->prec >= 0)
			spec->prec = 0;
	}
	if (spec->prec < 0)
		spec->prec = ft_strlen(*tmpstr);
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

int	resolve_s(t_spec *spec, char *str)
{
	char	*tmp;
	char	*newstr;

	tmp = str;
	resolve_spec_s(spec, &tmp);
	newstr = ft_calloc(spec->prec + 1, sizeof(char));
	if (!newstr)
		return (-1);
	ft_memcpy(newstr, tmp, spec->prec);
	tmp = add_padding(spec, newstr);
	if (!tmp)
		return (-1);
	spec->str = tmp;
	spec->len = ft_strlen(spec->str);
	return (spec->len);
}
