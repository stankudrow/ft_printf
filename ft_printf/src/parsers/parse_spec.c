/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:58:16 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/03 21:53:33 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_spec(t_fmt *fmt, t_spec *spec)
{
	if (set_flags(fmt, spec))
		if (set_width(fmt, spec) && set_precision(fmt, spec))
			if (set_length(fmt, spec))
				return (set_type(fmt, spec));
	return (ERROR);
}

int	parse_spec(t_fmt *fmt)
{
	t_spec	*spec;
	int		status;

	status = ERROR;
	if (*fmt->fcp == '%')
	{
		fmt->fcp++;
		spec = create_spec();
		if (spec)
		{
			status = set_spec(fmt, spec);
			//if (status == SUCCESS)
			//	status = resolve_spec(fmt, spec);
			destroy_spec(&spec);
		}
	}
	return (status);
}
