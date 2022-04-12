/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:54:58 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/12 23:10:20 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_status	buffer_fmtstr(t_fmt *fmt)
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
	newstr = ft_memjoin(fmt->str, fmt->total, substr, sublen);
	free(substr);
	if (!newstr)
		return (FAILURE);
	free(fmt->str);
	fmt->str = newstr;
	fmt->fpp = fmt->fcp;
	if (pf_intsum_overflow(fmt->total, sublen))
		return (ERROR);
	fmt->total += sublen;
	return (OK);
}

static int	finish_fmt(t_fmt *fmt, char **strp, t_bool exitcode)
{
	int	total;

	if (exitcode == EXIT_SUCCESS)
	{
		if (buffer_fmtstr(fmt) == OK)
		{
			total = fmt->total;
			*strp = fmt->str;
			free(fmt);
			return (total);
		}
	}
	del_fmt(&fmt);
	*strp = NULL;
	return (ERROR);
}

int	ft_vasprintf(char **strp, const char *fmt, va_list ap)
{
	t_fmt	*fmt_s;

	fmt_s = init_fmt(strp, fmt, ap);
	if (!fmt_s)
		return (ERROR);
	while (*fmt_s->fcp)
	{
		if (pf_intsum_overflow(fmt_s->fcp - fmt_s->fpp, 1))
			return (finish_fmt(fmt_s, strp, EXIT_FAILURE));
		if (*fmt_s->fcp == '%')
		{
			if (buffer_fmtstr(fmt_s) != OK)
				return (finish_fmt(fmt_s, strp, EXIT_FAILURE));
			if (parse_spec(fmt_s) == ERROR)
				return (finish_fmt(fmt_s, strp, EXIT_FAILURE));
		}
		else
			fmt_s->fcp++;
	}
	return (finish_fmt(fmt_s, strp, EXIT_SUCCESS));
}
