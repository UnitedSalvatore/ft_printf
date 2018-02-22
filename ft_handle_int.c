/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:18:22 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/22 16:10:10 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdarg.h>
#include "ft_printf.h"

static intmax_t	ft_get_size(va_list *arg, enum e_size *size)
{
	intmax_t	num;

	num = va_arg(*arg, intmax_t);
	if (*size == HH)
		return ((signed char)num);
	if (*size == H)
		return ((short)num);
	if (*size == LL)
		return ((long)num);
	if (*size == L)
		return ((long long)num);
	if (*size == J)
		return (num);
	if (*size == Z)
		return ((size_t)num);
	else
		return ((int)num);
}

void			ft_handle_int(const char *format, va_list *arg, t_arg *spec)
{
	intmax_t	nbr;
	t_num		prop;
	uintmax_t	unbr;

	nbr = ft_get_size(arg, &spec->size);
	prop.sign = '\0';
	if (spec->plus)
		prop.sign = '+';
	else if (spec->space)
		prop.sign = ' ';
	if (nbr >= 0)
		unbr = nbr;
	else
	{
		unbr = -nbr;
		prop.sign = '-';
	}
	prop.prefix = NULL;
	prop.base = 10;
	prop.digits = "0123456789";
	if (spec->is_precision)
		spec->zero = 0;
	ft_handle_num(spec, unbr, &prop);
}
