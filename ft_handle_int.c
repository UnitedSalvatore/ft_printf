/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:18:22 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/21 11:57:10 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

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

static void		ft_handle_num(t_arg *spec, uintmax_t num, t_num *prop)
{
	char		buf[sizeof(intmax_t) * 8];
	char		*p;
	int			length;

	p = &buf[sizeof(intmax_t) * 8 - 1];
	*p-- = prop->digits[num % prop->base];
	while (num /= prop->base)
		*p-- = prop->digits[num % prop->base];
	(*(p + 1) == '0' && spec->is_precision && spec->precision == 0) ? ++p : 0;
	length = &buf[sizeof(intmax_t) * 8 - 1] - p;
	spec->min_width -= length;
	(prop->sign) ? --spec->min_width : 0;
	if (spec->is_precision && (spec->precision -= length) >= 0)
		spec->min_width -= spec->precision;
	else
		spec->precision = 0;
	if (spec->min_width > 0 && !spec->minus && !spec->zero)
		ft_put_width(0, spec);
	(prop->sign) ? ft_add_to_buf(prop->sign, &spec->buffer) : 0;
	while (spec->precision--)
		ft_add_to_buf('0', &spec->buffer);
	(spec->min_width > 0 && spec->zero) ? ft_put_width(0, spec) : 0;
	while (++p != &buf[sizeof(intmax_t) * 8])
		ft_add_to_buf(*p, &spec->buffer);
	(spec->min_width > 0 && spec->minus) ? ft_put_width(0, spec) : 0;
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
