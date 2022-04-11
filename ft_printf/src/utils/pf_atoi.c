/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:57:02 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/11 18:57:03 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	ft_pre_skip(const char **nptr, char *sign)
{
	while (ft_isspace(**nptr))
		(*nptr)++;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			*sign = -1;
		(*nptr)++;
	}
	if (ft_isdigit(**nptr))
	{
		while (**nptr == '0')
			(*nptr)++;
		return (True);
	}
	return (False);
}

/* nbr is an always positive number while in the loop of ft_atoi */
static int	ft_isoverflow(long nbr, unsigned char digit, char sign)
{
	if (sign < 0)
		return ((INT_MIN / 10 > nbr) || \
				(INT_MIN + digit > -10 * nbr));
	if (sign > 0)
		return ((INT_MAX / 10 < nbr) || \
				(INT_MAX - digit < 10 * nbr));
	return (-1);
}

static t_bool	ft_post_skip(const char *nptr)
{
	while (ft_isdigit(*nptr))
		nptr++;
	return (*nptr == '\0');
}

t_bool	pf_atoi(int *number, const char *nptr)
{
	long	nbr;
	char	sign;
	t_bool	status;

	sign = 1;
	nbr = 0;
	status = False;
	if (ft_pre_skip(&nptr, &sign))
	{
		while (ft_isdigit(*nptr))
		{
			if (ft_isoverflow(nbr, *nptr - '0', sign))
				return (False);
			nbr = 10 * nbr + (*nptr - '0');
			nptr++;
		}
		status = ft_post_skip(nptr);
		if (status)
			*number = nbr * sign;
	}
	return (status);
}
