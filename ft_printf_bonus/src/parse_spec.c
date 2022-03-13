/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:58:16 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/13 13:32:47 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_spec	*init_spec(void)
{
	t_spec	*spec;

	spec = ft_calloc(1, sizeof(t_spec));
	if (spec)
	{
		spec->sharp = False;
		spec->zero = False;
		spec->zfill = ' ';
		spec->minus = False;
		spec->space = False;
		spec->sign = False;
		spec->sfill = ' ';
		spec->width = -1;
		spec->prec = -1;
		spec->type = '\0';
		spec->str = NULL;
		spec->len = -1;
		return (spec);
	}
	return (NULL);
}

static t_bool	set_flags(t_fmt *fmt, t_spec *spec)
{
	while (ft_strchr(AVAIL_FLAGS, *fmt->fcp))
	{
		if (*fmt->fcp == '#')
			spec->sharp = True;
		if (*fmt->fcp == '0')
			spec->zero = True;
		if (*fmt->fcp == '+')
			spec->sign = True;
		if (*fmt->fcp == '-')
			spec->minus = True;
		if (*fmt->fcp == ' ')
			spec->space = True;
		fmt->fcp++;
	}
	if (spec->minus || spec->sign)
		spec->zero = False;
	if (spec->zero)
		spec->zfill = '0';
	return (*fmt->fcp);
}

static t_bool	set_widprec(t_fmt *fmt, t_spec *spec)
{
	spec->width = ft_atoi(fmt->fcp);
	while (ft_isdigit(*fmt->fcp))
		fmt->fcp++;
	if (*fmt->fcp == '.')
	{
		fmt->fcp++;
		spec->prec = ft_atoi(fmt->fcp);
		if (spec->prec < 0)
			spec->prec = -1;
		while (ft_isdigit(*fmt->fcp))
			fmt->fcp++;
	}
	return (*fmt->fcp);
}

static t_bool	set_type(t_fmt *fmt, t_spec *spec)
{
	t_bool	status;

	status = False;
	if (ft_strchr(AVAIL_TYPES, *fmt->fcp))
	{
		spec->type = *fmt->fcp;
		status = True;
	}
	return (status);
}

/*
	-1 - a parsing error ('\0' reached)
	0 - an unavailable type ('\0' not reached)
	1 - a successfully parsed specification
*/
int	parse_spec(t_fmt *fmt, va_list ap)
{
	t_spec	*spec;
	int		status;

	status = -1;
	if (*fmt->fcp == '%')
	{
		fmt->fcp++;
		spec = init_spec();
		if (spec)
		{
			if (set_flags(fmt, spec) && \
				set_widprec(fmt, spec) && \
				set_type(fmt, spec))
					status = resolve_spec(fmt, spec, ap);
			else if (*fmt->fcp)
				status = 0;
		}
		free(spec->str);
		free(spec);
	}
	return (status);
}
