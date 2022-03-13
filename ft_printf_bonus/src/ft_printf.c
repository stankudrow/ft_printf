/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:06:47 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/13 12:26:05 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		total;
	char	*str;

	str = NULL;
	va_start(ap, fmt);
	total = ft_vasprintf(&str, fmt, ap);
	va_end(ap);
	if (total >= 0)
	{
		ft_putstr_fd(STDOUT_FILENO, str);
		free(str);
	}
	return (total);
}
