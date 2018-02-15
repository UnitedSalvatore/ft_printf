/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specification.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:19:28 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/15 00:48:51 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_specification(t_arg *spec)
{
	printf("spec->minus |%i|\n", spec->minus);
	printf("spec->zero |%i|\n", spec->zero);
	printf("spec->plus |%i|\n", spec->plus);
	printf("spec->space |%i|\n", spec->space);
	printf("spec->hash |%i|\n", spec->hash);
	\
	printf("spec->min_width |%i|\n", spec->min_width);
	printf("spec->is_precision |%i|\n", spec->is_precision);
	printf("spec->precision |%i|\n", spec->precision);
	printf("spec->size |%i|\n", spec->size);
}
