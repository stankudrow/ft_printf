/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:43:54 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/18 22:43:55 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	set_spec(t_fmt *fmt, t_spec *spec)
{
	t_status	status;

	status = set_flags(fmt, spec);
	if (status == OK)
	{
		status = set_width(fmt, spec);
		if (status == OK)
		{
			status = set_precision(fmt, spec);
			if (status == OK)
			{
				status = set_length(fmt, spec);
				if (status == OK)
					return (set_type(fmt, spec));
			}
		}
	}
	return (status);
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
