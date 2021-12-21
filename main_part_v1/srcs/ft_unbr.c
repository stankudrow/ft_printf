/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:15:52 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/21 23:15:52 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_base_fd(int fd, ULL unbr, const char *base_set, UC base)
{
	if (unbr >= base)
		ft_putunbr_base_fd(fd, unbr / base, base_set, base);
	ft_putchar_fd(fd, base_set[unbr % base]);
}

int	ft_putunbr_base_width(ULL unbr, UC nbase)
{
	int	width;

	if (!unbr)
		return (1);
	width = 0;
	while (unbr)
	{
		width++;
		unbr /= nbase;
	}
	return (width);
}
