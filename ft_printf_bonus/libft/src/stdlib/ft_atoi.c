/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:07:36 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/07 18:32:29 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

// libft-unit-test - that is why such an implementation
int	ft_atoi(const char *nptr)
{
	return (ft_atoi_base(nptr, "0123456789"));
}
