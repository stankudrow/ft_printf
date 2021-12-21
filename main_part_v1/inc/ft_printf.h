/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:17:48 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/21 23:17:48 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>

// type aliases
# define ULL unsigned long long
# define UI unsigned int
# define UC unsigned char

// for NULL value treatement
# define SNULL "(null)"
# define SNULL_LEN 6

// number bases
# define HBL "0123456789abcdef"
# define HBU "0123456789ABCDEF"
# define DB "0123456789"
# define OB "01234567"

int		ft_printf(const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);

// parsers
int		ft_parse_chr_fd(int fd, char chr);
int		ft_parse_int_fd(int fd, int nbr, char *base);
int		ft_parse_ptr_fd(int fd, ULL addr);
int		ft_parse_spec_fd(int fd, char chr, va_list ap);
int		ft_parse_str_fd(int fd, const char *str);
int		ft_parse_ull_fd(int fd, ULL unbr, const char *base);

// utils
bool	ft_is_valid_base(const char *base);
void	ft_putnbr_base_fd(int fd, int nbr, const char *base_set, UC base);
int		ft_putnbr_base_width(int nbr, UC nbase);
void	ft_putchar_fd(int fd, const char c);
size_t	ft_strlen(const char *s);
void	ft_putunbr_base_fd(int fd, ULL unbr, const char *base_set, UC base);
int		ft_putunbr_base_width(ULL unbr, UC nbase);

#endif