/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:46:48 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/07 14:29:25 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

// warning: the function does not mimic the strncat function
char	*ft_strncat(char *dst, const char *src, size_t n)
{
	ft_strlcat(dst, src, ft_strlen(dst) + n + 1);
	return (dst);
}
