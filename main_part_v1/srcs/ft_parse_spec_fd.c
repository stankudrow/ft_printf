/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spec_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:48 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/21 23:16:48 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_spec_fd(int fd, char chr, va_list ap)
{
	if (chr == 'p')
		return (ft_parse_ptr_fd(fd, va_arg(ap, ULL)));
	else if (chr == 'x')
		return (ft_parse_ull_fd(fd, va_arg(ap, UI), HBL));
	else if (chr == 'X')
		return (ft_parse_ull_fd(fd, va_arg(ap, UI), HBU));
	else if (chr == 'u')
		return (ft_parse_ull_fd(fd, va_arg(ap, UI), DB));
	else if (chr == 'd' || chr == 'i')
		return (ft_parse_int_fd(fd, va_arg(ap, int), DB));
	else if (chr == 'o')
		return (ft_parse_int_fd(fd, va_arg(ap, UI), OB));
	else if (chr == 's')
		return (ft_parse_str_fd(fd, va_arg(ap, char *)));
	else if (chr == '%')
		return (ft_parse_chr_fd(fd, '%'));
	else if (chr == 'c')
		return (ft_parse_chr_fd(fd, va_arg(ap, int)));
	else
		return (-1);
}
