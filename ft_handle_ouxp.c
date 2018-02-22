/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ouxp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 04:09:11 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/22 20:53:22 by ypikul           ###   ########.fr       */
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

void				ft_handle_o(const char *format, va_list *arg, t_arg *spec)
{
	uintmax_t	unbr;
	t_num		prop;

	unbr = ft_get_size(arg, &spec->size);
	prop.sign = '\0';
	if (spec->hash && (unbr || (!unbr && spec->is_precision && !spec->precision)))
		prop.prefix = "0";
	else
		prop.prefix = "";
	prop.base = 8;
	prop.digits = "01234567";
	if (spec->is_precision)
		spec->zero = 0;
	ft_handle_unum(spec, unbr, &prop);
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
	ft_handle_unum(spec, unbr, &prop);
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
	ft_handle_unum(spec, unbr, &prop);
}

void				ft_handle_p(const char *format, va_list *arg, t_arg *spec)
{
	uintmax_t	unbr;
	t_num		prop;

	unbr = (uintmax_t)va_arg(*arg, void *);
	prop.sign = '\0';
	prop.prefix = "0x";
	prop.digits = "0123456789abcdef";
	prop.base = 16;
	if (spec->is_precision)
		spec->zero = 0;
	ft_handle_unum(spec, unbr, &prop);
}