/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:17:11 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/21 23:17:11 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_int_fd(int fd, int nbr, char *base)
{
	UC	nbase;

	if (ft_is_valid_base(base))
	{
		nbase = ft_strlen(base);
		ft_putnbr_base_fd(fd, nbr, base, nbase);
		return (ft_putnbr_base_width(nbr, nbase));
	}
	return (0);
}
