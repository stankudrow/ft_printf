/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:54:28 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/11 17:54:28 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	set_flags(t_fmt*fmt, t_spec*spec)
{
	while (*fmt->fcp)
	{
		if (*fmt->fcp == '-')
			spec->flags.minus = True;
		else if (*fmt->fcp == '+')
			spec->flags.plus = True;
		else if (*fmt->fcp == '#')
			spec->flags.sharp = True;
		else if (*fmt->fcp == ' ')
			spec->flags.space = True;
		else if (*fmt->fcp == '0')
			spec->flags.zero = True;
		else
			break ;
		fmt->fcp++;
	}
	if (*fmt->fcp == '\0')
		return (ERROR);
	return (OK);
}
