/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:45:25 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/13 10:09:11 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdbool.h"
#include "ft_stdlib.h"
#include "ft_string.h"

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
		if (!ft_isalnum(base[bci]))
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

/* base should be checked before and has no 0, 1 values */
static size_t	ft_get_numlen(int nbr, int nbase)
{
	size_t	len;

	len = 0;
	if (nbr <= 0)
		len++;
	if (nbr < 0)
	{
		nbr /= -nbase;
		len++;
	}
	while (nbr)
	{
		nbr /= nbase;
		len++;
	}
	return (len);
}

static char	*ft_init_itoa(int nbr, const char *base, int *sign, int *nbase)
{
	char	*str;
	size_t	nbrlen;

	if (ft_is_valid_base(base))
	{
		*nbase = ft_strlen(base);
		nbrlen = ft_get_numlen(nbr, *nbase);
		str = ft_calloc(nbrlen + 1, sizeof(char));
		if (str)
		{
			*sign = 1;
			if (nbr < 0)
				*sign = -1;
			return (str);
		}
	}
	return (NULL);
}

static void	ft_strrev(char *str)
{
	char	*left;
	char	tmp;

	left = str;
	while (*str)
		str++;
	while (left < --str)
	{
		tmp = *left;
		*left++ = *str;
		*str = tmp;
	}
}

/* thanks to calloc, no need to NULL-terminate an alloc'd string */
char	*ft_itoa_base(int nbr, const char *base)
{
	char	*str;
	int		pos;
	int		nbase;
	int		sign;

	str = ft_init_itoa(nbr, base, &sign, &nbase);
	if (!str)
		return (NULL);
	pos = 0;
	if (nbr < 0)
	{
		str[pos++] = base[-(nbr % nbase)];
		nbr /= -nbase;
	}
	while (nbr)
	{
		str[pos++] = base[nbr % nbase];
		nbr /= nbase;
	}
	if (!(nbr || pos))
		str[pos++] = base[0];
	if (sign < 0)
		str[pos++] = '-';
	ft_strrev(str);
	return (str);
}
