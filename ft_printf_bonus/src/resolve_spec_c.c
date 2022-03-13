/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_spec_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:13:06 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/13 15:11:36 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	resolve_flags_c(t_spec *spec)
{
	spec->zero = False;
	spec->zfill = ' ';
	if (spec->width < 0)
		spec->width = 0;
	if (!spec->width)
		spec->width++;
}

int	resolve_c(t_spec *spec, int chr)
{
	char	*str;

	resolve_flags_c(spec);
	str = ft_calloc(spec->width + 1, sizeof(char));
	if (!str)
		return (-1);
	ft_memset(str, spec->zfill, spec->width);
	if (!spec->minus)
		str[spec->width - 1] = chr;
	else
		str[0] = chr;
	spec->str = str;
	spec->len = spec->width;
	return (spec->len);
}
