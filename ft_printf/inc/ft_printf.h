/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:42:34 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/14 23:55:48 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <wchar.h>

# include "ft_ctype.h"
# include "ft_putters.h"
# include "ft_stdbool.h"
# include "ft_stdlib.h"
# include "ft_string.h"

# define UI unsigned int

# define HBL "0123456789abcdef"
# define HBU "0123456789ABCDEF"
# define DB "0123456789"
# define OB "01234567"

# ifdef __linux__
#  define NULLSTR "(null)"
#  define NULLPTR "(nil)"
# elif __APPLE__
#  define NULLSTR "(null)"
#  define NULLPTR "(null)"
# else
#  error "This project is only for MacOS/Linux OS."
# endif

# define AVAIL_FLAGS "#0- +"
# define INT_TYPES "cspdiuxX%"

typedef enum e_status
{
	ERROR = -1,
	FAIL = 0,
	OK = 1
}	t_status;

/*
	fmt		-> a format string
	fpp		-> a previous position in fmt
	fcp		-> a current position in fmt
	str		-> the storage for an allocated formatted string
	total	-> the number of processed bytes
*/
typedef struct s_fmt
{
	va_list		ap;
	const char	*fmt;
	const char	*fpp;
	const char	*fcp;
	char		*str;
	int			total;
}	t_fmt;

typedef struct s_flags
{
	unsigned char	minus : 1;
	unsigned char	plus : 1;
	unsigned char	sharp : 1;
	unsigned char	space : 1;
	unsigned char	zero : 1;
}	t_flags;

typedef struct s_length
{
	unsigned char	hh : 1;
	unsigned char	h : 1;
	unsigned char	l : 1;
	unsigned char	ll : 1;
	unsigned char	z : 1;
	unsigned char	t : 1;
}	t_length;

typedef struct s_spec
{
	int			width;
	int			precision;
	t_flags		flags;
	t_length	length;
	char		type;
	size_t		len;
	char		*str;
}	t_spec;

int			ft_printf(const char *fmt, ...);
int			ft_vasprintf(char **strp, const char *fmt, va_list ap);

t_bool		pf_intabs_overflow(int nbr);
t_bool		pf_intsum_overflow(int nbr1, int nbr2);
t_bool		pf_atoi(int *number, const char *nptr);
char		*pf_pad_right(const char *str, unsigned char chr, size_t times);
char		*pf_pad_left(const char *str, unsigned char chr, size_t times);

t_fmt		*init_fmt(char **strp, const char *fmt, va_list ap);
void		del_fmt(t_fmt **fmt);
t_spec		*init_spec(void);
void		del_spec(t_spec **spec);

t_status	parse_spec(t_fmt *fmt);
t_status	set_spec(t_fmt *fmt, t_spec *spec);
t_status	set_flags(t_fmt*fmt, t_spec *spec);
t_status	set_width(t_fmt *fmt, t_spec *spec);
t_status	set_precision(t_fmt *fmt, t_spec *spec);
t_status	set_length(t_fmt *fmt, t_spec *spec);
t_status	set_type(t_fmt *fmt, t_spec *spec);

t_status	resolve_spec(t_fmt *fmt, t_spec *spec);
t_status	resolve_chr(t_fmt *fmt, t_spec *spec);
t_status	resolve_str(t_fmt *fmt, t_spec *spec);
t_status	resolve_ptr(t_fmt *fmt, t_spec *spec);
t_status	resolve_unbr(t_fmt *fmt, t_spec *spec);

/*
int			resolve_di(t_spec *spec, int nbr);
*/

#endif