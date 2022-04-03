/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:07:36 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/07 18:32:41 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

// libft-unit-test - that is why such an implementation
unsigned int	ft_atoui(const char *nptr)
{
	return (ft_atoui_base(nptr, "0123456789"));
}
