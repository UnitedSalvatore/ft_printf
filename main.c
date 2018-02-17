/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:15:16 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/17 20:33:22 by ypikul           ###   ########.fr       */
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

	i = 0;
	j = 0;
	setlocale(LC_ALL, "");
	i = printf("%+11.9d\n", 2051);
	printf("%d\n", i);
	j = ft_printf("%C\n", 2051);
	printf("%d\n", j);
	return (0);
}
