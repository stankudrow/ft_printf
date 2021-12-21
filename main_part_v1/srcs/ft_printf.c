/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:15:17 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/21 23:15:17 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// https://en.wikipedia.org/wiki/Printf_format_string
// https://www.cplusplus.com/reference/cstdio/printf/
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;

	va_start(ap, format);
	total = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (total);
}
