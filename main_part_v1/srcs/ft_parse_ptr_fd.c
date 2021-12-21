/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:17:05 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/21 23:17:05 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_ptr_fd(int fd, ULL addr)
{
	UC	nbase;

	if (ft_is_valid_base(HBL))
	{
		nbase = ft_strlen(HBL);
		write(fd, "0x", 2);
		ft_putunbr_base_fd(fd, addr, HBL, nbase);
		return (2 + ft_putunbr_base_width(addr, nbase));
	}
	return (0);
}
