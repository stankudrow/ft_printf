/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 01:56:42 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/07 18:16:30 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_ctype.h"
#include "ft_stdbool.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#define UC unsigned char

static t_bool	ft_is_valid_base(const char *base)
{
	size_t	blen;
	size_t	bci;
	size_t	bcj;

	blen = ft_strlen(base);
	if (blen < 2 || blen > 36)
		return (False);
	bci = 0;
	while (bci < blen)
	{
		if (!ft_isdigit(base[bci]))
			return (False);
		bcj = 0;
		while (bcj < bci)
		{
			if (base[bcj] == base[bci])
				return (False);
			bcj++;
		}
		bci++;
	}
	return (True);
}

static void	ft_skip(const char **nptr, char *sign)
{
	while (ft_isspace(**nptr))
		(*nptr)++;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			*sign = -1;
		(*nptr)++;
	}
}

// nbr is always a positive number while in the loop of ft_atoi
static int	ft_isoverflow(long nbr, UC digit, UC nbase, char sign)
{
	if (sign < 0)
		return ((LONG_MIN / nbase > nbr) || \
				(LONG_MIN + digit > -nbase * nbr));
	if (sign > 0)
		return ((LONG_MAX / nbase < nbr) || \
				(LONG_MAX - digit < nbase * nbr));
	return (-1);
}

// libft-unit-test - that is why such an implementation
// not for push_swap project
int	ft_atoi_base(const char *nptr, const char *base)
{
	long			nbr;
	char			sign;
	size_t			nbase;
	unsigned char	digit;

	if (!ft_is_valid_base(base))
		return (0);
	nbase = ft_strlen(base);
	sign = 1;
	nbr = 0;
	ft_skip(&nptr, &sign);
	while (*nptr && ft_strchr(base, *nptr))
	{
		digit = ft_strchr(base, *nptr) - base;
		if (ft_isoverflow(nbr, digit, nbase, sign))
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nbr = nbase * nbr + (digit % nbase);
		nptr++;
	}
	return (sign * nbr);
}
