/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ull_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:19 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/21 23:16:19 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_ull_fd(int fd, ULL unbr, const char *base)
{
	UC	nbase;

	if (ft_is_valid_base(base))
	{
		nbase = ft_strlen(base);
		ft_putunbr_base_fd(fd, unbr, base, nbase);
		return (ft_putunbr_base_width(unbr, nbase));
	}
	return (0);
}
