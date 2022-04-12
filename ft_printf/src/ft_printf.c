/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:51:32 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/12 22:48:47 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ft_putstr_fd had to be replaced with write syscall. */
int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		total;
	char	*str;

	str = NULL;
	va_start(ap, fmt);
	total = ft_vasprintf(&str, fmt, ap);
	if (total >= 0)
	{
		write(STDOUT_FILENO, str, total);
		free(str);
	}
	va_end(ap);
	return (total);
}
