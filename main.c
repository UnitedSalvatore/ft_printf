/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:15:16 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/13 16:38:42 by ypikul           ###   ########.fr       */
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
	setlocale (LC_ALL, "");
	i = printf("|%6D|\n", 65);
	printf("%d\n", i);
	j = ft_printf("|%4c|\n", 97);
	printf("%d\n", j);
	return (0);
}
