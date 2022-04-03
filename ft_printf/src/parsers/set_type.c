/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:34:32 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/02 19:36:10 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_type(t_fmt *fmt, t_spec *spec)
{
	char	ctype;

	ctype = *fmt->fcp;
	if (ft_strchr(AVAIL_TYPES, ctype))
	{
		fmt->fcp++;
		fmt->fpp = fmt->fcp;
		spec->type = ctype;
		return (SUCCESS);
	}
	if (!ctype)
		return (ERROR);
	return (FAILURE);
}
