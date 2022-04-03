/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:39:25 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 00:39:25 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

static int	ft_isaf_up(int c)
{
	return (c >= 'A' && c <= 'F');
}

static int	ft_isaf_low(int c)
{
	return (c >= 'a' && c <= 'f');
}

int	ft_isxdigit(int c)
{
	return (ft_isdigit(c) || ft_isaf_up(c) || ft_isaf_low(c));
}
