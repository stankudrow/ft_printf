/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:59:53 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/03 13:14:07 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_char_short(t_fmt *fmt, t_spec *spec)
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
				return (SUCCESS);
			}
			return (ERROR);
		}
		return (FAILURE);
	}
	return (ERROR);
}

static int	set_long_long(t_fmt *fmt, t_spec *spec)
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
				return (SUCCESS);
			}
			return (ERROR);
		}
		return (FAILURE);
	}
	return (ERROR);
}

int	set_length(t_fmt *fmt, t_spec *spec)
{
	char	len;

	len = *fmt->fcp;
	if (len == 'h')
		return (set_char_short(fmt, spec));
	if (len == 'l')
		return (set_long_long(fmt, spec));
	return (*fmt->fcp);
}
