/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:15:16 by ypikul            #+#    #+#             */
/*   Updated: 2017/12/18 15:30:05 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int i;

	i = 0;
	i = printf("%s\n", "Test");
	printf("%i\n", i);
	i = ft_printf("%s\n", "Test");
	ft_printf("%i\n", i);
	return 0;
}
