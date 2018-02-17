/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:18:22 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/17 20:45:45 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdarg.h>

static int		ft_num_length(intmax_t num, const int base)
{
	size_t i;

	i = 1;
	if (num < 0)
		i++;
	while (num /= 10)
		i++;
	return (i);
}

static intmax_t	ft_get_size(va_list *arg, enum e_size *size)
{
	if (*size == HH)
		return ((signed char)va_arg(*arg, intmax_t));
	if (*size == H)
		return ((short)va_arg(*arg, intmax_t));
	if (*size == LL)
		return ((long)va_arg(*arg, intmax_t));
	if (*size == L)
		return ((long long)va_arg(*arg, intmax_t));
	if (*size == J)
		return (va_arg(*arg, intmax_t));
	if (*size == Z)
		return ((size_t)va_arg(*arg, intmax_t));
	else
		return ((int)va_arg(*arg, intmax_t));
}

void			ft_handle_int(const char *format, va_list *arg, t_arg *spec)
{
	intmax_t	nbr;
	int			size;
	char		sign;

	spec->is_precision ? spec->zero = 0 : 0;
	nbr = ft_get_size(arg, &spec->size);
	size = ft_num_length(nbr, 10);
	if (spec->is_precision && spec->precision > spec->min_width)
		spec->min_width == spec->precision;
	if ()
}
