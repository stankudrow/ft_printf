/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:16:28 by stanislav         #+#    #+#             */
/*   Updated: 2021/12/21 23:16:28 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_str_fd(int fd, const char *str)
{
	size_t	len;

	if (!str)
		return (write(fd, SNULL, SNULL_LEN));
	len = ft_strlen(str);
	return (write(fd, str, len));
}
