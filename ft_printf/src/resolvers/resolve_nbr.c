/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:05:05 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/18 18:05:05 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	get_arg_nbr(t_fmt *fmt, t_spec *spec)
{
	intmax_t	nbr;

	if (spec->length.hh)
		nbr = (char)(va_arg(fmt->ap, int));
	else if (spec->length.h)
		nbr = (short)(va_arg(fmt->ap, int));
	else if (spec->length.l)
		nbr = (long)(va_arg(fmt->ap, long int));
	else if (spec->length.ll)
		nbr = (long long)(va_arg(fmt->ap, long long int));
	else
		nbr = (int)(va_arg(fmt->ap, int));
	if (spec->flags.space && nbr >= 0)
		spec->sign = ' ';
	if (spec->flags.plus && nbr >= 0)
		spec->sign = '+';
	if (nbr < 0)
		spec->sign = '-';
	return ((intmax_t)nbr);
}

static t_status	save_nbr_str(t_spec *spec, intmax_t nbr)
{
	char	*str;

	if (!nbr && !spec->precision)
		str = ft_strdup("");
	else
		str = ft_lltoa(nbr);
	if (!str)
		return (ERROR);
	spec->str = str;
	str = ft_strtrim_left(spec->str, "-");
	if (!str)
		return (ERROR);
	free(spec->str);
	spec->str = str;
	spec->len = ft_strlen(str);
	if (spec->precision >= (int)spec->len)
		spec->precision -= (int)spec->len;
	else
		spec->precision = 0;
	return (OK);
}

static t_status	precise_nbr_str(t_spec *spec)
{
	t_status	status;

	if (!spec->len)
		return (OK);
	status = pf_pad_spec_left(spec, '0', spec->precision);
	if (status != OK)
		return (status);
	if (spec->sign && spec->width > 0)
		spec->width--;
	if (spec->width >= (int)spec->len)
		spec->width -= (int)spec->len;
	else
		spec->width = 0;
	if (spec->flags.zero)
	{
		status = pf_pad_spec_left(spec, '0', spec->width);
		spec->width = 0;
	}
	return (status);
}

static t_status	pad_nbr_str(t_spec *spec)
{
	t_status	status;

	if (spec->sign)
	{
		status = pf_pad_spec_left(spec, spec->sign, 1);
		if (status != OK)
			return (status);
	}
	if (spec->flags.minus)
		return (pf_pad_spec_right(spec, ' ', spec->width));
	else
		return (pf_pad_spec_left(spec, spec->fill, spec->width));
}

t_status	resolve_nbr(t_fmt *fmt, t_spec *spec)
{
	intmax_t	nbr;
	t_status	status;

	nbr = get_arg_nbr(fmt, spec);
	status = save_nbr_str(spec, nbr);
	if (status != OK)
		return (status);
	status = precise_nbr_str(spec);
	if (status != OK)
		return (status);
	status = pad_nbr_str(spec);
	if (status != OK)
		return (status);
	return (status);
}
