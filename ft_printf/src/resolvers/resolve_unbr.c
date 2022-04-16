#include "ft_printf.h"

static uintmax_t	get_arg_unbr(t_fmt *fmt, t_spec *spec)
{
	uintmax_t	unbr;

	if (spec->length.hh)
		unbr = (unsigned char)(va_arg(fmt->ap, unsigned int));
	else if (spec->length.h)
		unbr = (unsigned short)(va_arg(fmt->ap, unsigned int));
	else if (spec->length.l)
		unbr = (unsigned long)(va_arg(fmt->ap, unsigned long int));
	else if (spec->length.ll)
		unbr = (unsigned long long)(va_arg(fmt->ap, unsigned long long int));
	else
		unbr = (unsigned int)(va_arg(fmt->ap, unsigned int));
	return ((uintmax_t)unbr);
}

static t_status	prefixate(t_spec *spec, uintmax_t unbr)
{
	char	*str;

	if (spec->flags.sharp && unbr && spec->type != 'u')
	{
		if (spec->type == 'o')
			str = ft_strjoin("0", spec->str);
		if (spec->type == 'x')
			str = ft_strjoin("0x", spec->str);
		if (spec->type == 'X')
			str = ft_strjoin("0X", spec->str);
		if (!str)
			return (ERROR);
		free(spec->str);
		spec->str = str;
		spec->len = ft_strlen(str);
		free(str);
	}
	return (OK);
}

static t_status	acc_unbr_str(t_spec *spec, uintmax_t unbr)
{
	char	*str;

	if (!unbr && !spec->precision)
		str = ft_strdup("");
	else
	{
		str = NULL;
		if (spec->type == 'o')
			str = ft_ulltoa_base(unbr, OB);
		else if (spec->type == 'u')
			str = ft_ulltoa_base(unbr, DB);
		else if (spec->type == 'x')
			str = ft_ulltoa_base(unbr, HBL);
		else if (spec->type == 'X')
			str = ft_ulltoa_base(unbr, HBU);
	}
	if (!str)
		return (ERROR);
	if (spec->precision < 0)
		spec->precision = 0;
	spec->str = pf_pad_left(str, '0', spec->precision);
	free(str);
	return (prefixate(spec, unbr));
}

t_status	resolve_unbr(t_fmt *fmt, t_spec *spec)
{
	t_status	status;
	char		*unbrstr;

	status = acc_unbr_str(spec, get_arg_unbr(fmt, spec));
	if (status != OK)
		return (status);
	if (spec->flags.minus)
		unbrstr = pf_pad_right(spec->str, ' ', spec->width);
	else
		unbrstr = pf_pad_left(spec->str, ' ', spec->width);
	if (!unbrstr)
		return (ERROR);
	free(spec->str);
	spec->str = unbrstr;
	spec->len = ft_strlen(spec->str);
	return (OK);
}
