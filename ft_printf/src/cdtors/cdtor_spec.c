/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdtor_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:18:04 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/03 21:58:03 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	*create_spec(void)
{
	t_spec	*spec;

	spec = ft_calloc(1, sizeof(t_spec));
	if (!spec)
		return (NULL);
	spec->width = -1;
	spec->precision = -1;
	spec->type = 0;
	spec->str = NULL;
	spec->len = 0;
	return (spec);
}

void	destroy_spec(t_spec **spec)
{
	free(*spec);
	*spec = NULL;
}
