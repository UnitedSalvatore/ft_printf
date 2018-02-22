/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:39:18 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/22 16:11:45 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

void		ft_handle_num(t_arg *spec, uintmax_t num, t_num *prop)
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

void			ft_handle_unum(t_arg *spec, uintmax_t num, t_num *prop)
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
