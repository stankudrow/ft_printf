/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:17:29 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/21 23:17:29 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_fd(int fd, int nbr, const char *base_set, UC base)
{
	if (nbr < 0)
	{
		ft_putchar_fd(fd, '-');
		if (nbr <= -base)
			ft_putnbr_base_fd(fd, nbr / -base, base_set, base);
		ft_putchar_fd(fd, base_set[-(nbr % base)]);
	}
	else
	{
		if (nbr >= base)
			ft_putnbr_base_fd(fd, nbr / base, base_set, base);
		ft_putchar_fd(fd, base_set[nbr % base]);
	}
}

int	ft_putnbr_base_width(int nbr, UC nbase)
{
	int	width;

	width = 0;
	if (nbr <= 0)
		width++;
	while (nbr)
	{
		width++;
		nbr /= nbase;
	}
	return (width);
}
