/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:41:27 by stanislav         #+#    #+#             */
/*   Updated: 2022/01/20 23:41:27 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isgraph(int c)
{
	return (c > 32 && c < 127);
}