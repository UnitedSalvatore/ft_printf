/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:15:16 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/11 19:33:09 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include "ft_printf.h"
#include "libft.h"

int main(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	//setlocale (LC_ALL, "");
	i = printf("%#X\n", 0xFF);
	printf("%d\n", i);
	j = ft_printf("Test\n%");
	printf("%d\n", j);
	return (0);
}
