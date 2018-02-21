/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:56:03 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/21 02:42:38 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

void			ft_handle_num(t_arg *spec, uintmax_t num, t_num *prop)
{
	char		buf[sizeof(intmax_t) * 8];
	char		*p;
	const char	digits[] = "0123456789abcdef0123456789ABCDF";
	int			length;

	length = 0;
	if (num == 0)
		prop->prefix = NULL;
	p = &buf[sizeof(intmax_t) * 8 - 1];
	*p-- = digits[num % prop->base + prop->big_char];
	while (num /= prop->base)
		*p-- = digits[num % prop->base + prop->big_char];
	length = &buf[sizeof(intmax_t) * 8 - 1] - p;
	spec->min_width -= length;
	if (prop->sign)
		--spec->min_width;
	if (prop->prefix)
		spec->min_width -= ft_strlen(prop->prefix);
	if (spec->is_precision)
		if (spec->precision >= length)
		{
			spec->precision -= length;
			spec->min_width -= spec->precision;
		}
	if (spec->min_width > 0 && !spec->minus && !spec->zero)
		ft_put_width(0, spec);
	if (prop->sign)
		ft_add_to_buf(prop->sign, &spec->buffer);
	if (prop->prefix)
		while (*prop->prefix)
			ft_add_to_buf(*prop->prefix++, &spec->buffer);
	if (spec->is_precision)
		while (spec->precision--)
			ft_add_to_buf('0', &spec->buffer);
	if (spec->min_width > 0 && spec->zero)
		ft_put_width(0, spec);
	while (++p != &buf[sizeof(intmax_t) * 8])
		ft_add_to_buf(*p, &spec->buffer);
	if (spec->min_width > 0 && spec->minus)
		ft_put_width(0, spec);
}
