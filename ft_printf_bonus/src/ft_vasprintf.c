/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:07:04 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/13 12:34:16 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_fmt	*init_fmt(char **strp, const char *fmt, va_list ap)
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

static t_bool	buffer_fmt(t_fmt *fmt)
{
	size_t	sublen;
	char	*substr;
	char	*newstr;

	if (fmt->fcp >= fmt->fpp)
	{
		sublen = fmt->fcp - fmt->fpp;
		substr = ft_strndup(fmt->fpp, sublen);
		if (substr)
		{
			newstr = ft_strjoin(fmt->str, substr);
			free(substr);
			if (newstr)
			{
				free(fmt->str);
				fmt->str = newstr;
				fmt->fpp = fmt->fcp;
				fmt->total += sublen;
				return (True);
			}
		}
	}
	return (False);
}

static int	finish_fmt(t_fmt *fmt, char **strp, t_bool status)
{
	int	total;

	total = -1;
	if (status == 0)
	{
		if (buffer_fmt(fmt))
		{
			total = fmt->total;
			*strp = fmt->str;
			free(fmt);
			return (total);
		}
	}
	free(fmt->str);
	*strp = NULL;
	free(fmt);
	return (total);
}

int	ft_vasprintf(char **strp, const char *fmt, va_list ap)
{
	t_fmt	*fmt_s;

	fmt_s = init_fmt(strp, fmt, ap);
	if (!fmt_s)
		return (-1);
	while (*fmt_s->fcp)
	{
		if (*fmt_s->fcp == '%')
		{
			if (!buffer_fmt(fmt_s))
				return (finish_fmt(fmt_s, strp, EXIT_FAILURE));
			if (parse_spec(fmt_s, ap) < 0)
				return (finish_fmt(fmt_s, strp, EXIT_FAILURE));
			fmt_s->fpp = fmt_s->fcp + 1;
		}
		fmt_s->fcp++;
	}
	return (finish_fmt(fmt_s, strp, EXIT_SUCCESS));
}
