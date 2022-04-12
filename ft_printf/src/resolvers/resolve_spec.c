/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:11:20 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/12 23:35:01 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_status	attach_specstr(t_fmt *fmt, t_spec *spec)
{
	char	*tmp;

	tmp = fmt->str;
	fmt->str = ft_memjoin(fmt->str, fmt->total, spec->str, spec->len);
	free(tmp);
	if (!fmt->str)
		return (ERROR);
	if (pf_intsum_overflow(fmt->total, spec->len))
		return (FAILURE);
	fmt->total += spec->len;
	return (OK);
}

static t_status	resolve_intspec(t_fmt *fmt, t_spec *spec)
{
	t_status	status;

	if (spec->type == '%' || spec->type == 'c')
		status = resolve_c(fmt, spec);
	if (spec->type == 's')
		status = resolve_s(fmt, spec);
	/*
	if (ctype == 'd' || ctype == 'i')
		res = resolve_di(spec, va_arg(fmt->ap, int));
	if (ctype == 'o')
		res = resolve_o(spec, va_arg(fmt->ap, UI));
	if (ctype == 'u')
		res = resolve_u(spec, va_arg(fmt->ap, UI));
	if (ctype == 'x')
		res = resolve_uxl(spec, va_arg(fmt->ap, UI));
	if (ctype == 'X')
		res = resolve_uxu(spec, va_arg(fmt->ap, UI));
	if (ctype == 'p')
		res = resolve_p(spec, va_arg(fmt->ap, UI));
	*/
	if (status != OK)
		return (status);
	return (attach_specstr(fmt, spec));
}

/* The else branch is reserved for float types resolving. */
t_status	resolve_spec(t_fmt *fmt, t_spec *spec)
{
	if (!spec->type)
		return (ERROR);
	if (ft_strchr(INT_TYPES, spec->type))
		return (resolve_intspec(fmt, spec));
	else
		return (FAILURE);
}
