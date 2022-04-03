/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:17:32 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/03 22:52:06 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_flags(t_fmt*fmt, t_spec*spec)
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
	return (SUCCESS);
}
