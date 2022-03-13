/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:08:23 by stanislav         #+#    #+#             */
/*   Updated: 2022/02/20 15:08:23 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_mem.h"

// thanks to @jbelinda and @thera for insights
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	total;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	if (size > (size_t)-1 / nmemb)
		return (NULL);
	total = nmemb * size;
	mem = malloc(total);
	if (mem)
		ft_memset(mem, 0, total);
	return (mem);
}
// ft_bzero(mem, total); -> ft_memset(mem, 0, total);