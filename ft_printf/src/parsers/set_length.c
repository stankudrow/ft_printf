/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:54:58 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/11 17:54:58 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_status	set_char_short(t_fmt *fmt, t_spec *spec)
{
	if (*fmt->fcp)
	{
		if (*fmt->fcp == 'h')
		{
			fmt->fcp++;
			if (*fmt->fcp)
			{
				if (*fmt->fcp == 'h')
					spec->length.hh = True;
				else
					spec->length.h = True;
				return (OK);
			}
			return (ERROR);
		}
		return (FAILURE);
	}
	return (ERROR);
}

static t_status	set_long_long(t_fmt *fmt, t_spec *spec)
{
	if (*fmt->fcp)
	{
		if (*fmt->fcp == 'l')
		{
			fmt->fcp++;
			if (*fmt->fcp)
			{
				if (*fmt->fcp == 'l')
					spec->length.ll = True;
				else
					spec->length.l = True;
				return (OK);
			}
			return (ERROR);
		}
		return (FAILURE);
	}
	return (ERROR);
}

t_status	set_length(t_fmt *fmt, t_spec *spec)
{
	char	len;

	len = *fmt->fcp;
	if (len == 'h')
		return (set_char_short(fmt, spec));
	else if (len == 'l')
		return (set_long_long(fmt, spec));
	else if (len == 'z')
		spec->length.z = True;
	else if (len == 't')
		spec->length.t = True;
	if (*fmt->fcp)
		return (OK);
	return (ERROR);
}
