/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:14:25 by stanislav         #+#    #+#             */
/*   Updated: 2022/04/02 17:19:30 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

/*
int	main(void)
{
	int			ret;
	const char	*fmt;

	fmt = "| %% %% %% |";
	ret = printf(fmt, 0, '1', '2');
	printf("\nprintf ret = %d#\n", ret);
	ret = ft_printf(fmt, 0, '1', '2');
	printf("\nft_printf ret = %d#\n\n", ret);

	fmt = "| %c %c %c |";
	ret = printf(fmt, 0, '1', '2');
	printf("\nprintf ret = %d#\n", ret);
	ret = ft_printf(fmt, 0, '1', '2');
	printf("\nft_printf ret = %d#\n\n", ret);

	fmt = "| NULL %s NULL |";
	ret = printf(fmt, NULL);
	printf("\nprintf ret = %d#\n", ret);
	ret = ft_printf(fmt, NULL);
	printf("\nft_printf ret = %d#\n\n", ret);

	fmt = "| %s %s |";
	ret = printf(fmt, "", "-");
	printf("\nprintf ret = %d#\n", ret);
	ret = ft_printf(fmt, "", "-");
	printf("\nft_printf ret = %d#\n\n", ret);

	return (0);
}
*/

void	main(int argc, char **argv)
{
	ft_printf("\n");
	ft_printf("fkfjhskjf  sf gf ");
	ft_printf(NULL);
	ft_printf("%# +-0 warden", '4');
}
