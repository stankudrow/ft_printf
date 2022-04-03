/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdtor_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:21:02 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/03 21:57:18 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt	*create_fmt(char **strp, const char *fmt, va_list ap)
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

void	destroy_fmt(t_fmt **fmt)
{
	if ((*fmt)->str)
		free((*fmt)->str);
	free(*fmt);
	*fmt = NULL;
}
