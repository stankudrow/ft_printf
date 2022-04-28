/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:45:12 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/28 07:08:35 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_arg_str(t_fmt *fmt, t_spec *spec)
{
	char	*strarg;
	char	*str;

	strarg = va_arg(fmt->ap, char *);
	if (strarg == NULL)
	{
		strarg = NULLSTR;
		if (ft_strcmp(fmt->os, "linux") == 0)
		{
			if (spec->precision > 0 && spec->precision < (int)ft_strlen(strarg))
				spec->precision = 0;
		}
	}
	if (spec->precision < 0)
		spec->precision = (int)ft_strlen(strarg);
	str = ft_calloc(spec->precision + 1, sizeof(unsigned char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, strarg, spec->precision + 1);
	spec->len = ft_strlen(str);
	return (str);
}

t_status	resolve_str(t_fmt *fmt, t_spec *spec)
{
	char	*str;

	str = get_arg_str(fmt, spec);
	if (!str)
		return (ERROR);
	if ((int)spec->len >= spec->width)
		spec->width = 0;
	else
		spec->width -= spec->len;
	if (spec->flags.minus)
		spec->str = pf_pad_right(str, spec->fill, spec->width);
	else
		spec->str = pf_pad_left(str, spec->fill, spec->width);
	free(str);
	if (!spec->str)
		return (ERROR);
	spec->len = ft_strlen(spec->str);
	return (OK);
}
