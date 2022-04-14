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

static t_status	get_unbr_str(t_spec *spec, uintmax_t unbr)
{
	char	*str;

	

	if (!unbr && !spec->precision)
		spec->str = ft_strdup("");
	else
		spec->str = ft_uitoa_base(unbr, base);
	if (spec->precision < 0)
		spec->precision = 0;
	str = pf_pad_left(spec->str, '0', spec->precision);
	return (prefixate(ft_alternate(unbr, spec));
}

t_status	resolve_unbr(t_fmt *fmt, t_spec *spec)
{
	char	*unbrstr;

	unbrstr = get_unbr_str(spec, get_arg_unbr(fmt, spec));
	if (!unbrstr)
		return (ERROR);
	if (spec->flags.minus)
		spec->str = pf_pad_right(unbrstr, ' ', spec->width);
	else
		spec->str = pf_pad_left(unbrstr, ' ', spec->width);
	free(unbrstr);
	if (!spec->str)
		return (ERROR);
	spec->len = ft_strlen(spec->str);
	return (OK);
}
