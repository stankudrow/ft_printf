/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:45:25 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/08 17:13:32 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdbool.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#define UI unsigned int

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
static UI	ft_get_numlen(UI unbr, int nbase)
{
	UI	len;

	len = 0;
	if (!unbr)
		len++;
	while (unbr)
	{
		unbr /= nbase;
		len++;
	}
	return (len);
}

static char	*ft_init_uitoa(UI unbr, const char *base, UI *nbase)
{
	char	*str;
	UI		unbrlen;

	if (ft_is_valid_base(base))
	{
		*nbase = ft_strlen(base);
		unbrlen = ft_get_numlen(unbr, *nbase);
		str = ft_calloc(unbrlen + 1, sizeof(char));
		if (str)
			return (str);
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
char	*ft_uitoa_base(UI unbr, const char *base)
{
	char	*str;
	UI		pos;
	UI		nbase;

	str = ft_init_uitoa(unbr, base, &nbase);
	if (!str)
		return (NULL);
	pos = 0;
	while (unbr)
	{
		str[pos++] = base[unbr % nbase];
		unbr /= nbase;
	}
	if (!(unbr || pos))
		str[pos++] = base[0];
	ft_strrev(str);
	return (str);
}
