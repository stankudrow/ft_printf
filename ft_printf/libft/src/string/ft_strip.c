/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:41:18 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/28 01:42:10 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	ft_count_chr(const char *str, char chr)
{
	size_t	nstr;
	size_t	nchr;

	nstr = 0;
	nchr = 0;
	while (str[nstr])
	{
		if (str[nstr] == chr)
			nchr++;
		nstr++;
	}
	return (nchr);
}

char	*ft_strip(const char *str, char chr)
{
	size_t	nstr;
	size_t	nchr;
	char	*new;

	new = malloc(ft_strlen(str) - ft_count_chr(str, chr) + 1);
	if (new)
	{
		nstr = 0;
		nchr = 0;
		while (str[nstr])
		{
			if (str[nstr] != chr)
				new[nchr++] = str[nstr];
			nstr++;
		}
		new[nchr] = '\0';
	}
	return (new);
}
