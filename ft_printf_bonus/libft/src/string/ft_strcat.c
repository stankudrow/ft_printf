/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:46:48 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/07 14:27:55 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

// warning: the function does not mimic the strcat function
char	*ft_strcat(char *dst, const char *src)
{
	ft_strlcat(dst, src, ft_strlen(dst) + ft_strlen(src) + 1);
	return (dst);
}
