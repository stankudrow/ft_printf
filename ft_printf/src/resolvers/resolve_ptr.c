/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:52:35 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/18 11:49:24 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_arg_ptr(t_fmt *fmt)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(fmt->ap, void *);
	if (!ptr)
		str = ft_strdup(NULLPTR);
	else
		str = ft_ulltoa_base((uintptr_t)ptr, HBL);
	return (str);
}

static t_status	pad_ptr(t_spec *spec)
{
	char	*str;

	spec->precision = ft_strlen(spec->str);
	if (spec->width > spec->precision)
		spec->width -= spec->precision;
	else
		spec->width = 0;
	if (spec->flags.minus)
		str = pf_pad_right(spec->str, spec->fill, spec->width);
	else
		str = pf_pad_left(spec->str, spec->fill, spec->width);
	if (!str)
		return (ERROR);
	free(spec->str);
	spec->str = str;
	spec->len = ft_strlen(str);
	return (OK);
}

static t_status	prefixate_ptr(t_spec *spec)
{
	char	*str;

	str = ft_strjoin("0x", spec->str);
	if (!str)
		return (ERROR);
	free(spec->str);
	spec->str = str;
	spec->len = ft_strlen(str);
	return (OK);
}

t_status	resolve_ptr(t_fmt *fmt, t_spec *spec)
{
	t_status	status;
	char		*str;

	str = get_arg_ptr(fmt);
	if (!str)
		return (ERROR);
	spec->str = str;
	status = OK;
	if (ft_strcmp(NULLPTR, spec->str))
		status = prefixate_ptr(spec);
	if (status != OK)
		return (status);
	return (pad_ptr(spec));
}
