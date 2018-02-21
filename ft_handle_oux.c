/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_oux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 04:09:11 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/21 10:53:29 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

static uintmax_t	ft_get_size(va_list *arg, enum e_size *size)
{
	uintmax_t	num;

	num = va_arg(*arg, uintmax_t);
	if (*size == HH)
		return ((unsigned char)num);
	if (*size == H)
		return ((unsigned short)num);
	if (*size == LL)
		return ((unsigned long)num);
	if (*size == L)
		return ((unsigned long long)num);
	if (*size == J)
		return (num);
	if (*size == Z)
		return ((size_t)num);
	else
		return ((unsigned int)num);
}

static void			ft_handle_num(t_arg *spec, uintmax_t num, t_num *prop)
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
	spec->min_width -= ft_strlen(prop->prefix) + length;
	if (spec->is_precision && (spec->precision -= length) >= 0)
		spec->min_width -= spec->precision;
	else
		spec->precision = 0;
	if (spec->min_width > 0 && !spec->minus && !spec->zero)
		ft_put_width(0, spec);
	while (*prop->prefix)
		ft_add_to_buf(*prop->prefix++, &spec->buffer);
	if (spec->is_precision)
		while (spec->precision--)
			ft_add_to_buf('0', &spec->buffer);
	(spec->min_width > 0 && spec->zero) ? ft_put_width(0, spec) : 0;
	while (++p != &buf[sizeof(intmax_t) * 8])
		ft_add_to_buf(*p, &spec->buffer);
	(spec->min_width > 0 && spec->minus) ? ft_put_width(0, spec) : 0;
}

void				ft_handle_o(const char *format, va_list *arg, t_arg *spec)
{
	uintmax_t	unbr;
	t_num		prop;

	unbr = ft_get_size(arg, &spec->size);
	prop.sign = '\0';
	if (spec->hash)
		prop.prefix = "0";
	else
		prop.prefix = "";
	prop.base = 8;
	prop.digits = "01234567";
	if (spec->is_precision)
		spec->zero = 0;
	ft_handle_num(spec, unbr, &prop);
}

void				ft_handle_u(const char *format, va_list *arg, t_arg *spec)
{
	uintmax_t	unbr;
	t_num		prop;

	unbr = ft_get_size(arg, &spec->size);
	prop.sign = '\0';
	prop.prefix = "";
	prop.base = 10;
	prop.digits = "0123456789";
	if (spec->is_precision)
		spec->zero = 0;
	ft_handle_num(spec, unbr, &prop);
}

void				ft_handle_x(const char *format, va_list *arg, t_arg *spec)
{
	uintmax_t	unbr;
	t_num		prop;

	unbr = ft_get_size(arg, &spec->size);
	prop.sign = '\0';
	if (unbr && spec->hash)
	{
		if (*format == 'X')
			prop.prefix = "0X";
		else
			prop.prefix = "0x";
	}
	else
		prop.prefix = "";
	if (*format == 'X')
		prop.digits = "0123456789ABCDEF";
	else
		prop.digits = "0123456789abcdef";
	prop.base = 16;
	if (spec->is_precision)
		spec->zero = 0;
	ft_handle_num(spec, unbr, &prop);
}
