/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:52:35 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/15 00:29:25 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*init_arg_ptr(t_fmt *fmt)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(fmt->ap, void *);
	if (!ptr)
		str = ft_strdup(NULLPTR);
	else
		str = ft_ulltoa_base((uintptr_t)ptr, HBL);
	if (!str)
		return (NULL);
	return (str);
}

static t_status	pad_ptr(t_spec *spec)
{
	char	*str;

	if (spec->precision > (int)ft_strlen(spec->str))
		spec->len = spec->precision;
	if (spec->flags.minus)
		str = pf_pad_right(spec->str, ' ', spec->width);
	else
		str = pf_pad_left(spec->str, ' ', spec->width);
	if (!str)
		return (ERROR);
	free(spec->str);
	spec->str = str;
	spec->len = ft_strlen(str);
	return (OK);
}

static t_status	prefix_ptr(t_spec *spec)
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

	str = init_arg_ptr(fmt);
	if (!str)
		return (ERROR);
	spec->str = str;
	if (!ft_strcmp(NULLPTR, spec->str))
	{
		spec->len = ft_strlen(str);
		return (OK);
	}
	status = pad_ptr(spec);
	if (status != OK)
		return (status);
	return (prefix_ptr(spec));
}
