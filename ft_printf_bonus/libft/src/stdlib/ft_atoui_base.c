/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 01:56:42 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/07 18:30:03 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_ctype.h"
#include "ft_stdbool.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#define UL unsigned long
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

static void	ft_skip(const char **nptr)
{
	while (ft_isspace(**nptr))
		(*nptr)++;
	if (**nptr == '+')
		(*nptr)++;
}

// nbr is always a positive number while in the loop of ft_atoi
static int	ft_isoverflow(UL nbr, UC digit, UC nbase)
{
	return ((ULONG_MAX / nbase < nbr) || (ULONG_MAX - digit < nbase * nbr));
}

// libft-unit-test - that is why such an implementation
// not for push_swap project
unsigned int	ft_atoui_base(const char *nptr, const char *base)
{
	UL		nbr;
	size_t	nbase;
	UC		digit;

	if (!ft_is_valid_base(base))
		return (0);
	nbase = ft_strlen(base);
	nbr = 0;
	ft_skip(&nptr);
	while (*nptr && ft_strchr(base, *nptr))
	{
		digit = ft_strchr(base, *nptr) - base;
		if (ft_isoverflow(nbr, digit, nbase))
			return (0);
		nbr = nbase * nbr + (digit % nbase);
		nptr++;
	}
	return (nbr);
}
