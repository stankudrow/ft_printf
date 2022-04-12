/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:21:53 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/12 23:50:26 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wint_t	get_argchar(t_fmt *fmt, t_spec *spec)
{
	wint_t	chr;

	if (spec->length.l)
		chr = va_arg(fmt->ap, wint_t);
	else
		chr = va_arg(fmt->ap, int);
	return (chr);
}

static t_status	resolve_char(t_fmt *fmt, t_spec *spec)
{
	wint_t	chr;

	chr = get_argchar(fmt, spec);
	if (spec->width < 0)
		spec->width = 1;
	spec->str = ft_calloc(spec->width + 1, sizeof(unsigned char));
	if (!spec->str)
		return (ERROR);
	if (spec->flags.zero)
		ft_memset(spec->str, '0', spec->width);
	else
		ft_memset(spec->str, ' ', spec->width);
	if (spec->flags.minus)
		spec->str[0] = chr;
	else
		spec->str[spec->width - 1] = chr;
	spec->len = spec->width;
	return (OK);
}

static t_status	resolve_percent(t_spec *spec)
{
	char	*str;

	str = ft_strdup("%");
	if (!str)
		return (ERROR);
	if (spec->width < 0)
		spec->width = 1;
	if (spec->width > 0)
		spec->width--;
	if (spec->flags.minus)
		spec->str = pf_pad_right(str, ' ', spec->width);
	else if (spec->flags.zero)
		spec->str = pf_pad_left(str, '0', spec->width);
	else
		spec->str = pf_pad_left(str, ' ', spec->width);
	free(str);
	if (!spec->str)
		return (ERROR);
	spec->len = ft_strlen(spec->str);
	return (OK);
}

t_status	resolve_c(t_fmt *fmt, t_spec *spec)
{
	if (spec->type)
	{
		if (spec->type == '%')
			return (resolve_percent(spec));
		if (spec->type == 'c')
			return (resolve_char(fmt, spec));
	}
	return (ERROR);
}
