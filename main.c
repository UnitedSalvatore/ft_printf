/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:15:16 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/22 20:46:45 by ypikul           ###   ########.fr       */
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
	i = printf("|%#.3o|\n", 1);
	printf("%d\n", i);
	j = ft_printf("|%#.3o|\n", 1);
	printf("%d\n", j);
	printf("------------------\n");
	printf("#o - |%#o|\n", 0);
	ft_printf("#o - |%#o|\n", 0);
	printf("------------------\n");
	printf("#x - |%#x|\n", 0);
	ft_printf("#x - |%#x|\n", 0);
	printf("------------------\n");
	printf(".0d - |%.0d|\n", 0);
	ft_printf(".0d - |%.0d|\n", 0);
	printf("------------------\n");
	printf(".0o - |%.0o|\n", 0);
	ft_printf(".0o - |%.0o|\n", 0);
	printf("------------------\n");
	printf(".0x - |%.0x|\n", 0);
	ft_printf(".0x - |%.0x|\n", 0);
	printf("------------------\n");
	printf("#.0d - |%#.0d|\n", 0);
	ft_printf("#.0d - |%#.0d|\n", 0);
	printf("------------------\n");
	printf("#.0o - |%#.0o|\n", 0);
	ft_printf("#.0o - |%#.0o|\n", 0);
	printf("------------------\n");
	printf("#.0x - |%#.0x|\n", 0);
	ft_printf("#.0x - |%#.0x|\n", 0);
	printf("==================\n");
	printf("#o - |%#o|\n", 1);
	ft_printf("#o - |%#o|\n", 1);
	printf("------------------\n");
	printf("#x - |%#x|\n", 1);
	ft_printf("#x - |%#x|\n", 1);
	printf("------------------\n");
	printf(".0d - |%.0d|\n", 1);
	ft_printf(".0d - |%.0d|\n", 1);
	printf("------------------\n");
	printf(".0o - |%.0o|\n", 1);
	ft_printf(".0o - |%.0o|\n", 1);
	printf("------------------\n");
	printf(".0x - |%.0x|\n", 1);
	ft_printf(".0x - |%.0x|\n", 1);
	printf("------------------\n");
	printf("#.0d - |%#.0d|\n", 1);
	ft_printf("#.0d - |%#.0d|\n", 1);
	printf("------------------\n");
	printf("#.0o - |%#.0o|\n", 1);
	ft_printf("#.0o - |%#.0o|\n", 1);
	printf("------------------\n");
	printf("#.0x - |%#.0x|\n", 1);
	ft_printf("#.0x - |%#.0x|\n", 1);
	printf("==================\n");
	return (0);
}
