/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:45:05 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/18 22:45:05 by stanislav        ###   ########.fr       */
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
		return (FAIL);
	fmt->total += spec->len;
	return (OK);
}

static t_status	resolve_intspec(t_fmt *fmt, t_spec *spec)
{
	t_status	status;

	if (spec->type == 'd' || spec->type == 'i')
		status = resolve_nbr(fmt, spec);
	else if (spec->type == 'o')
		status = resolve_unbr(fmt, spec);
	else if (spec->type == 'u')
		status = resolve_unbr(fmt, spec);
	else if (spec->type == 'x')
		status = resolve_unbr(fmt, spec);
	else if (spec->type == 'X')
		status = resolve_unbr(fmt, spec);
	else if (spec->type == 'p')
		status = resolve_ptr(fmt, spec);
	else if (spec->type == 's')
		status = resolve_str(fmt, spec);
	else if (spec->type == '%' || spec->type == 'c')
		status = resolve_chr(fmt, spec);
	else
		return (FAIL);
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
		return (FAIL);
}
