/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:33:56 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/02 17:33:54 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_width(t_fmt *fmt, t_spec *spec)
{
	if (ft_isdigit(*fmt->fcp))
		spec->width = ft_atoi(fmt->fcp);
	while (ft_isdigit(*fmt->fcp))
		fmt->fcp++;
	if (*fmt->fcp)
		return (SUCCESS);
	return (ERROR);
}

int	set_precision(t_fmt *fmt, t_spec *spec)
{
	if (*fmt->fcp == '.')
	{
		fmt->fcp++;
		spec->precision = ft_atoi(fmt->fcp);
		while (ft_isdigit(*fmt->fcp))
			fmt->fcp++;
		if (!*fmt->fcp)
			return (ERROR);
	}
	return (SUCCESS);
}
