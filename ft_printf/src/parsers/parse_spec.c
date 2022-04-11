/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:53:39 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/11 17:53:39 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	set_spec(t_fmt *fmt, t_spec *spec)
{
	if (set_flags(fmt, spec))
		if (set_width(fmt, spec) && set_precision(fmt, spec))
			if (set_length(fmt, spec))
				return (set_type(fmt, spec));
	return (ERROR);
}

t_status	parse_spec(t_fmt *fmt)
{
	t_spec		*spec;
	t_status	status;

	status = ERROR;
	if (*fmt->fcp == '%')
	{
		fmt->fcp++;
		spec = init_spec();
		if (spec)
		{
			status = set_spec(fmt, spec);
			if (status == OK)
				status = resolve_spec(fmt, spec);
			del_spec(&spec);
		}
	}
	return (status);
}
