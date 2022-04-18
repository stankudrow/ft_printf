/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_intop_overflow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:45:38 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/18 22:45:38 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	pf_intabs_overflow(int nbr)
{
	return (nbr == INT_MIN);
}

t_bool	pf_intsum_overflow(int nbr1, int nbr2)
{
	if (nbr2 > 0)
		return ((INT_MAX - nbr2) < nbr1);
	return ((INT_MIN - nbr2) > nbr1);
}
