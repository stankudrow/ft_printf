/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorton <mhorton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:08:57 by mhorton           #+#    #+#             */
/*   Updated: 2022/02/20 13:08:57 by mhorton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putters.h"

void	ft_putendl_fd(int fd, const char *str)
{
	ft_putstr_fd(fd, str);
	ft_putstr_fd(fd, "\n");
}
