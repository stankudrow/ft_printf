/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:44:18 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/18 22:44:18 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reset_flags(t_spec *spec)
{
	if (spec->flags.minus)
		spec->flags.zero = False;
	if ((spec->precision >= 0) && ft_strchr("diouxX", spec->type))
		spec->flags.zero = False;
	if (spec->flags.plus)
		spec->flags.space = False;
	if (spec->flags.zero)
		spec->fill = '0';
}

/* str[r]chr will not work if '\0' provided -> checking before */
t_status	set_type(t_fmt *fmt, t_spec *spec)
{
	char	ctype;

	ctype = *fmt->fcp;
	if (!ctype)
		return (ERROR);
	if (ft_strchr(INT_TYPES, ctype))
	{
		fmt->fcp++;
		fmt->fpp = fmt->fcp;
		spec->type = ctype;
		reset_flags(spec);
		return (OK);
	}
	return (FAIL);
}
