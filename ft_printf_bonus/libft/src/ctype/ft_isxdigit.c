/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorton <mhorton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:17:51 by mhorton           #+#    #+#             */
/*   Updated: 2022/02/20 12:17:52 by mhorton          ###   ########.fr       */
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
