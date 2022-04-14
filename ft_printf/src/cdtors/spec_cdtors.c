/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_cdtors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:50:22 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/14 20:31:54 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	*init_spec(void)
{
	t_spec	*spec;

	spec = ft_calloc(1, sizeof(t_spec));
	if (!spec)
		return (NULL);
	spec->width = 0;
	spec->precision = -1;
	spec->type = 0;
	spec->str = NULL;
	spec->len = 0;
	return (spec);
}

void	del_spec(t_spec **spec)
{
	if (spec)
	{
		if (*spec)
		{
			if ((*spec)->str)
				free((*spec)->str);
			free(*spec);
			*spec = NULL;
		}
	}
}
