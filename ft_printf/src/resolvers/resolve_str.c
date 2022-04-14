/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:32:57 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/15 00:11:26 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	resolve_str(t_fmt *fmt, t_spec *spec)
{
	char	*strarg;
	char	*str;

	strarg = va_arg(fmt->ap, char *);
	if (strarg == NULL)
		strarg = NULLSTR;
	if (spec->precision < 0)
		spec->precision = ft_strlen(strarg);
	str = ft_calloc(spec->precision + 1, sizeof(unsigned char));
	if (!str)
		return (ERROR);
	ft_strlcpy(str, strarg, spec->precision + 1);
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
