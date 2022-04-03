/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:13:06 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/22 00:28:49 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	resolve_c(t_spec *spec, int chr)
{
	if (spec->widprec->width == 0)
		spec->widprec->width++;
	if (chr == 0)
		spec->widprec->width--;
	spec->str = ft_calloc(spec->widprec->width + 1, sizeof(char));
	if (spec->str)
	{
		ft_memset(spec->str, ' ', spec->widprec->width);
		if (chr)
		{
			if (spec->flags->minus)
				spec->str[spec->widprec->width] = chr;
			else
				spec->str[0] = chr;
		}
		spec->len = spec->widprec->width;
		if (chr == 0)
			spec->len++;
		return (spec->len);
	}
	return (-1);
}
