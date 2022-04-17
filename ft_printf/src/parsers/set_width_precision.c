/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:59:14 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/17 23:51:37 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define WIDTH 0
#define PRECISION 1

static t_status	parse_star(t_fmt *fmt, t_spec *spec, unsigned char mode)
{
	if (*fmt->fcp != '*')
		return (FAIL);
	if (mode == WIDTH)
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
	if (mode == PRECISION)
	{
		spec->precision = va_arg(fmt->ap, int);
		if (spec->precision < 0)
			spec->precision = -1;
		fmt->fcp++;
	}
	if (!*fmt->fcp)
		return (ERROR);
	return (OK);
}

t_status	set_width(t_fmt *fmt, t_spec *spec)
{
	if (*fmt->fcp == '*')
		return (parse_star(fmt, spec, WIDTH));
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
			return (parse_star(fmt, spec, PRECISION));
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
