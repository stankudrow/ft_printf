#include "ft_printf.h"

static intmax_t	get_intarg(t_fmt *fmt, t_spec *spec)
{
	intmax_t	nbr;

	if (spec->flags.length.hh)
		nbr = (char)(va_arg(fmt->ap, int));
	else if (spec->flags.length.h)
		nbr = (short)(va_arg(fmt->ap, int));
	else if (spec->flags.length.l)
		nbr = (long)(va_arg(fmt->ap, long int));
	else if (spec->flags.length.ll)
		nbr = (long long)(va_arg(fmt->ap, long long int));
	else
		nbr = (int)(va_arg(fmt->ap, int));
	return ((intmax_t)nbr);
}

static char	*get_intstr(t_spec *spec, intmax_t nbr)
{
	char	*str;

	if (!nbr && (spec->precision < 0))
		str = ft_strdup("");
	else
	{
		if (d < 0)
		{
			spec->prefix = MINUS;
			d = (uintmax_t)(d * -1);
		}
		spec->output = ft_uitoa_base(d, DEC_BASE);
	}
}

static void	ft_pad(t_spec *spec)
{
	ft_padding_l(&spec->output, '0', spec->precision);
	if (spec->prefix)
		spec->width--;
	if (spec->flags & FLAG_MINUS)
		ft_padding_r(&spec->output, ' ', spec->width);
	else if ((spec->flags & FLAG_ZERO) && spec->precision < 0)
		ft_padding_l(&spec->output, '0', spec->width);
	ft_prefix(spec);
	if (spec->prefix)
		spec->width++;
	ft_padding_l(&spec->output, ' ', spec->width);
}

t_status	resolve_di(t_fmt *fmt, t_spec *spec)
{
	char	*nbrstr;

	nbrstr = get_intstr(spec, get_argint(fmt, spec);
	ft_convert(d, spec);
	ft_pad(spec);
	spec->len = ft_strlen(spec->output);
}
