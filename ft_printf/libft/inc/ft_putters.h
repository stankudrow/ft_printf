/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:43:33 by stanislav         #+#    #+#             */
/*   Updated: 2022/02/23 18:56:28 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTTERS_H
# define FT_PUTTERS_H

# include <unistd.h>

void	ft_putchar_fd(int fd, char chr);
void	ft_putendl_fd(int fd, const char *str);
void	ft_putnbr_base_fd(int fd, long long nbr, const char *base);
void	ft_putnbr_fd(int fd, long long nbr);
void	ft_putstr_fd(int fd, const char *str);
void	ft_putunbr_base_fd(int fd, unsigned long long nbr, const char *base);
void	ft_putunbr_fd(int fd, unsigned long long nbr);

#endif