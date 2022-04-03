/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:07:04 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/03 23:29:15 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	buffer_fmtstr(t_fmt *fmt)
{
	ptrdiff_t	sublen;
	char		*substr;
	char		*newstr;

	sublen = fmt->fcp - fmt->fpp;
	if (sublen < 0)
		return (FAILURE);
	substr = ft_strndup(fmt->fpp, sublen);
	if (!substr)
		return (FAILURE);
	newstr = ft_strjoin(fmt->str, substr);
	free(substr);
	if (!newstr)
		return (FAILURE);
	free(fmt->str);
	fmt->str = newstr;
	fmt->fpp = fmt->fcp;
	if (ft_is_int_overflow(fmt->total, '+', sublen))
		return (ERROR);
	fmt->total += sublen;
	return (SUCCESS);
}

static int	finish_fmt(t_fmt *fmt, char **strp, t_bool status)
{
	int	total;

	if (status == EXIT_SUCCESS)
	{
		if (buffer_fmtstr(fmt) == SUCCESS)
		{
			total = fmt->total;
			*strp = fmt->str;
			free(fmt);
			return (total);
		}
	}
	destroy_fmt(&fmt);
	*strp = NULL;
	return (ERROR);
}

int	ft_vasprintf(char **strp, const char *fmt, va_list ap)
{
	t_fmt	*fmt_s;

	fmt_s = create_fmt(strp, fmt, ap);
	if (!fmt_s)
		return (ERROR);
	while (*fmt_s->fcp)
	{
		if (ft_is_int_overflow(fmt_s->fcp - fmt_s->fpp, '+', 1))
			return (finish_fmt(fmt_s, strp, EXIT_FAILURE));
		if (*fmt_s->fcp == '%')
		{
			if (buffer_fmtstr(fmt_s) != SUCCESS)
				return (finish_fmt(fmt_s, strp, EXIT_FAILURE));
			if (parse_spec(fmt_s) == ERROR)
				return (finish_fmt(fmt_s, strp, EXIT_FAILURE));
		}
		else
			fmt_s->fcp++;
	}
	return (finish_fmt(fmt_s, strp, EXIT_SUCCESS));
}
