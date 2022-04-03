/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:54:06 by stanislav         #+#    #+#             */
/*   Updated: 2022/02/21 23:54:06 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putters.h"

void	ft_putunbr_fd(int fd, unsigned long long nbr)
{
	ft_putunbr_base_fd(fd, nbr, "0123456789");
}
