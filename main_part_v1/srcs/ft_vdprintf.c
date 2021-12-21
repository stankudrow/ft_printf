/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:15:28 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/21 23:15:28 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// a dull vdprintf implementation just to get the task done
// no bufferisation, no optimisation, no satisfaction
int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int	fsc;
	int	total;
	int	printed;

	fsc = 0;
	total = 0;
	while (format[fsc])
	{
		if (format[fsc] == '%')
		{
			printed = ft_parse_spec_fd(fd, format[fsc + 1], ap);
			if (printed != -1)
			{
				total += printed;
				fsc++;
			}
		}
		else
			total += write(fd, format + fsc, 1);
		fsc++;
	}
	return (total);
}
