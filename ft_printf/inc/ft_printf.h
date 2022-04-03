/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:40:32 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/03 21:54:45 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>

# include "ft_ctype.h"
# include "ft_putters.h"
# include "ft_stdbool.h"
# include "ft_stdlib.h"
# include "ft_string.h"

/* status codes of operations != exit codes */
# define ERROR -1
# define FAILURE 0
# define SUCCESS 1

# define UI unsigned int

# define HBL "0123456789abcdef"
# define HBU "0123456789ABCDEF"
# define DB "0123456789"
# define OB "01234567"

// #IF __UNIX__ ONE LOGIC IF MACOS - ANOTHER
# define NULLSTR "(null)"

# define AVAIL_FLAGS "#0- +"
# define AVAIL_TYPES "cspdiuxX%"

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
	const char	*str;
}	t_spec;

int		ft_printf(const char *fmt, ...);
int		ft_vasprintf(char **strp, const char *fmt, va_list ap);

t_fmt	*create_fmt(char **strp, const char *fmt, va_list ap);
void	destroy_fmt(t_fmt **fmt);
t_spec	*create_spec(void);
void	destroy_spec(t_spec **spec);

int		parse_spec(t_fmt *fmt);
int		set_spec(t_fmt *fmt, t_spec *spec);
int		set_flags(t_fmt*fmt, t_spec *spec);
int		set_width(t_fmt *fmt, t_spec *spec);
int		set_precision(t_fmt *fmt, t_spec *spec);
int		set_length(t_fmt *fmt, t_spec *spec);
int		set_type(t_fmt *fmt, t_spec *spec);

/*
char		*ft_pad_right(const char *str, unsigned char chr, size_t times);
char		*ft_pad_left(const char *str, unsigned char chr, size_t times);

int			resolve_spec(t_fmt *fmt_s, t_spec *spec);
int			resolve_c(t_spec *spec, int chr);
int			resolve_s(t_spec *spec, char *str);
int			resolve_di(t_spec *spec, int nbr);
int			resolve_o(t_spec *spec, UI unbr);
int			resolve_u(t_spec *spec, UI unbr);
int			resolve_uxl(t_spec *spec, UI unbr);
int			resolve_uxu(t_spec *spec, UI unbr);
int			resolve_p(t_spec *spec, UI unbr);
*/

char	ft_is_int_overflow(int nbr1, char op, int nbr2);

#endif