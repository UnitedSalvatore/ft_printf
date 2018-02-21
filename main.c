/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:15:16 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/21 02:36:31 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	int	i;
	int	j;
	int				x = 1 << 31;
	unsigned int	ux = 1 << 31;

	printf("|%s |\n|%s|\n", ft_itoa_base(x, 2), ft_uitoa_base(ux, 2));
	i = 0;
	j = 0;
	setlocale(LC_ALL, "");
	i = printf("|%%|\n", 0, 0);
	printf("%d\n", i);
	j = ft_printf("|%%|\n", 1);
	printf("%d\n", j);
	return (0);
}
