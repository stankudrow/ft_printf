/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_cdtors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:43:29 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/28 07:06:48 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	*init_fmt(char **strp, const char *fmt, va_list ap)
{
	t_fmt	*fmt_s;

	if (strp && fmt && ap)
	{
		fmt_s = ft_calloc(1, sizeof(t_fmt));
		if (fmt_s)
		{
			fmt_s->str = ft_calloc(1, sizeof(char));
			if (fmt_s->str)
			{
				fmt_s->os = OS;
				va_copy(fmt_s->ap, ap);
				fmt_s->fmt = fmt;
				fmt_s->fpp = fmt;
				fmt_s->fcp = fmt;
				fmt_s->total = 0;
				return (fmt_s);
			}
		}
		free(fmt_s);
	}
	return (NULL);
}

void	del_fmt(t_fmt **fmt)
{
	if (fmt)
	{
		if (*fmt)
		{
			if ((*fmt)->str)
				free((*fmt)->str);
			free(*fmt);
			*fmt = NULL;
		}
	}
}
