/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:52:16 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/31 22:56:04 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	ft_is_intsum_overflow(int nbr1, int nbr2)
{
	if (nbr2 > 0)
		return ((INT_MAX - nbr2) < nbr1);
	return ((INT_MIN - nbr2) > nbr1);
}

char	ft_is_int_overflow(int nbr1, char op, int nbr2)
{
	if (op == '+')
		return (ft_is_intsum_overflow(nbr1, nbr2));
	return (-1);
}
