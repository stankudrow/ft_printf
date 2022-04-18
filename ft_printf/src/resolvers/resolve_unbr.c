/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_unbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:45:20 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/18 22:45:21 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_arg_unbr(t_fmt *fmt, t_spec *spec)
{
	uintmax_t	unbr;

	if (spec->length.hh)
		unbr = (unsigned char)(va_arg(fmt->ap, unsigned int));
	else if (spec->length.h)
		unbr = (unsigned short)(va_arg(fmt->ap, unsigned int));
	else if (spec->length.l)
		unbr = (unsigned long)(va_arg(fmt->ap, unsigned long int));
	else if (spec->length.ll)
		unbr = (unsigned long long)(va_arg(fmt->ap, unsigned long long int));
	else
		unbr = (unsigned int)(va_arg(fmt->ap, unsigned int));
	return ((uintmax_t)unbr);
}

static t_status	save_unbr_str(t_spec *spec, uintmax_t unbr)
{
	char	*str;

	if (!unbr && !spec->precision)
		str = ft_strdup("");
	else
	{
		str = NULL;
		if (spec->type == 'o')
			str = ft_ulltoa_base(unbr, OB);
		else if (spec->type == 'u')
			str = ft_ulltoa_base(unbr, DB);
		else if (spec->type == 'x')
			str = ft_ulltoa_base(unbr, HBL);
		else if (spec->type == 'X')
			str = ft_ulltoa_base(unbr, HBU);
	}
	if (!str)
		return (ERROR);
	spec->str = str;
	spec->len = ft_strlen(str);
	if (spec->precision >= (int)spec->len)
		spec->precision -= (int)spec->len;
	else
		spec->precision = 0;
	return (OK);
}

static t_status	prefixate_unbr_str(t_spec *spec, uintmax_t unbr)
{
	char	*str;

	if (!spec->len)
		return (OK);
	str = pf_pad_left(spec->str, '0', spec->precision);
	if (!str)
		return (ERROR);
	free(spec->str);
	spec->str = str;
	if (spec->flags.sharp && unbr && spec->type != 'u')
	{
		if (spec->type == 'o')
			str = ft_strjoin("0", spec->str);
		if (spec->type == 'x')
			str = ft_strjoin("0x", spec->str);
		if (spec->type == 'X')
			str = ft_strjoin("0X", spec->str);
		if (!str)
			return (ERROR);
		free(spec->str);
		spec->str = str;
	}
	spec->len = ft_strlen(str);
	return (OK);
}

static t_status	pad_unbr_str(t_spec *spec)
{
	if (spec->width >= (int)spec->len)
		spec->width -= (int)spec->len;
	else
		spec->width = 0;
	if (spec->flags.minus)
		return (pf_pad_spec_right(spec, spec->fill, spec->width));
	else
		return (pf_pad_spec_left(spec, spec->fill, spec->width));
}

t_status	resolve_unbr(t_fmt *fmt, t_spec *spec)
{
	uintmax_t	unbr;
	t_status	status;

	unbr = get_arg_unbr(fmt, spec);
	status = save_unbr_str(spec, unbr);
	if (status != OK)
		return (status);
	status = prefixate_unbr_str(spec, unbr);
	if (status != OK)
		return (status);
	return (pad_unbr_str(spec));
}
