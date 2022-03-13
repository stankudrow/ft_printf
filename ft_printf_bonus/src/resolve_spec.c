/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:48:02 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/13 14:53:04 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	append_str(t_fmt *fmt, t_spec *spec)
{
	char	*tmp;

	tmp = fmt->str;
	fmt->str = ft_strjoin(fmt->str, spec->str);
	free(tmp);
	if (!fmt->str)
		return (False);
	fmt->total += spec->len;
	return (True); //*fmt->fcp
}

t_bool	resolve_spec(t_fmt *fmt, t_spec *spec, va_list ap)
{
	int	ctype;
	int	res;

	ctype = spec->type;
	res = -1;
	if (ctype == '%')
		res = resolve_c(spec, ctype);
	if (ctype == 'c')
		res = resolve_c(spec, va_arg(ap, int));
	if (ctype == 's')
		res = resolve_s(spec, va_arg(ap, char *));
	/*
	if (ctype == 'd' || ctype == 'i')
		res = resolve_di(spec, va_arg(ap, int), DB);
	if (ctype == 'o')
		res = resolve_o(spec, va_arg(ap, UI));
	if (ctype == 'u')
		res = resolve_u(spec, va_arg(ap, UI));
	if (ctype == 'x')
		res = resolve_uxl(spec, va_arg(ap, UI));
	if (ctype == 'X')
		res = resolve_uxu(spec, va_arg(ap, UI));
	if (ctype == 'p')
		res = resolve_p(spec, va_arg(ap, UI));
	*/
	if (res < 0)
		return (False);
	return (append_str(fmt, spec));
}
