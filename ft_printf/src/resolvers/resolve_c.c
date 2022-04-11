/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:21:53 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/11 22:25:19 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_char(t_fmt *fmt, t_spec *spec)
{
	wint_t	chr;
	char	*str;

	if (spec->type == 'c')
	{
		if (spec->length.l)
			chr = va_arg(fmt->ap, wint_t);
		else
			chr = va_arg(fmt->ap, int);
	}
	else if (spec->type == '%')
		chr = spec->type;
	else
		return (NULL);
	str = ft_strdup(" ");
	if (str)
	{
		str[0] = chr;
		return (str);
	}
	return (NULL);
}

t_status	resolve_c(t_fmt *fmt, t_spec *spec)
{
	char	*str;

	str = get_char(fmt, spec);
	if (str == NULL)
		return (ERROR);
	if (spec->width == -1)
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
	if (spec->str == NULL)
		return (ERROR);
	spec->len = ft_strlen(spec->str);
	return (OK);
}
