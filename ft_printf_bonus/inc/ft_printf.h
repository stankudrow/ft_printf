/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:40:32 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/13 14:15:48 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
//# include <stdint.h>
//# include <wchar.h>

# include "ft_ctype.h"
# include "ft_putters.h"
# include "ft_stdbool.h"
# include "ft_stdlib.h"
# include "ft_string.h"

# define UI unsigned int

/* number bases */
# define HBL "0123456789abcdef"
# define HBU "0123456789ABCDEF"
# define DB "0123456789"
# define OB "01234567"

// #IF __UNIX__ ONE LOGIC IF MACOS - ANOTHER
# define NULLSTR "(null)"

/*
	fmt		-> formatting string
	fpp		-> previous position in fmt
	fcp		-> current position in fmt
	str		-> to store allocated formatted string
	total	-> number of processed bytes
*/
typedef struct s_fmt
{
	const char	*fmt;
	const char	*fpp;
	const char	*fcp;
	char		*str;
	int			total;
}	t_fmt;

# define AVAIL_FLAGS "#0- +"
# define AVAIL_TYPES "cspdiuxX%"

/*
	alternative form - sharp ('#')
	zero padding -> nought ('0')
	left adjustement -> minus ('-')
	left blank -> space (' ')
	number sign -> sign ('+')
	zfill -> zero flag filler
	sfill -> sign flag filler
*/
typedef struct s_flags
{
	t_bool	sharp;
	t_bool	zero;
	char	zfill;
	t_bool	minus;
	t_bool	space;
	t_bool	sign;
	char	sfill;
	int		width;
	int		prec;
	char	type;
	char	*str;
	int		len;
}	t_spec;

int		ft_printf(const char *fmt, ...);
int		ft_vasprintf(char **strp, const char *fmt, va_list ap);

int		parse_spec(t_fmt *fmt, va_list ap);
t_bool	resolve_spec(t_fmt *fmt_s, t_spec *spec, va_list ap);
int		resolve_c(t_spec *spec, int chr);
int		resolve_s(t_spec *spec, char *str);
//char	*resolve_di(t_spec *spec, int nbr, const char *base);

#endif