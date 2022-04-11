/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:59:14 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/11 20:37:30 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* $m logic implementation appears to be tedious - * is enough. */

t_status	set_width(t_fmt *fmt, t_spec *spec)
{
	if (*fmt->fcp == '*')
	{
		spec->width = va_arg(fmt->ap, int);
		if (spec->width < 0)
		{
			if (pf_intabs_overflow(spec->width))
				return (ERROR);
			spec->width *= -1;
			spec->flags.minus = True;
		}
		fmt->fcp++;
	}
	if (ft_isdigit(*fmt->fcp))
	{
		if (pf_atoi(&spec->width, fmt->fcp) == False)
			return (ERROR);
		while (ft_isdigit(*fmt->fcp))
			fmt->fcp++;
	}
	if (*fmt->fcp)
		return (OK);
	return (ERROR);
}

t_status	set_precision(t_fmt *fmt, t_spec *spec)
{
	if (*fmt->fcp == '.')
	{
		fmt->fcp++;
		if (*fmt->fcp == '*')
		{
			spec->precision = va_arg(fmt->ap, int);
			if (spec->precision < 0)
				spec->precision = -1;
			fmt->fcp++;
		}
		if (ft_isdigit(*fmt->fcp))
		{
			if (pf_atoi(&spec->precision, fmt->fcp) == False)
				return (ERROR);
			while (ft_isdigit(*fmt->fcp))
				fmt->fcp++;
		}
		else
			spec->precision = 0;
	}
	if (!*fmt->fcp)
		return (ERROR);
	return (OK);
}
