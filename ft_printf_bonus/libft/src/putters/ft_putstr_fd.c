/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorton <mhorton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:09:47 by mhorton           #+#    #+#             */
/*   Updated: 2022/02/20 13:09:56 by mhorton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putters.h"
#include "ft_string.h"

void	ft_putstr_fd(int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}
