/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 02:12:44 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/15 09:44:27 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <wchar.h>

static void	ft_putwchar(wchar_t c, struct s_buffer *buffer)
{
	if (c <= 0x7F)
		ft_add_to_buf(c, buffer);
	else if (c <= 0x7FF)
	{
		ft_add_to_buf((c >> 6) + 0xC0, buffer);
		ft_add_to_buf((c & 0x3F) | 0x80, buffer);
	}
	else if (c <= 0xFFFF)
	{
		ft_add_to_buf((c >> 12) | 0xE0 , buffer);
		ft_add_to_buf(((c >> 6) & 0x3F) | 0xC0, buffer);
		ft_add_to_buf((c & 0x3F) | 0x80, buffer);
	}
	else if (c <= 0x1FFFFF)
	{
		ft_add_to_buf((c >> 18) | 0xF0 , buffer);
		ft_add_to_buf(((c >> 12) & 0x3F) | 0xC0, buffer);
		ft_add_to_buf(((c >> 6) & 0x3F) | 0xC0, buffer);
		ft_add_to_buf((c & 0x3F) | 0x80, buffer);
	}

}

static void	ft_handle_wchar(const char *format, va_list *arg, t_arg *spec)
{
	wchar_t	c;
	int		len;

	(void)(format);
	c = (wchar_t)va_arg(*arg, wint_t);
	if (c <= 0x7F)
		len = 1;
	else if (c <= 0x7FF)
		len = 2;
	else if (c <= 0xFFFF)
		len = 3;
	else if (c <= 0x1FFFFF)
		len = 4;
	if (spec->min_width && !spec->minus)
		ft_put_width(sizeof(char) * len, spec);
	ft_putwchar(c, &spec->buffer);
	if (spec->min_width && spec->minus)
		ft_put_width(sizeof(char) * len, spec);
}

void		ft_handle_char(const char *format, va_list *arg, t_arg *spec)
{
	if (spec->size == L)
		return (ft_handle_wchar(format, arg, spec));
	if (spec->min_width && !spec->minus)
		ft_put_width(sizeof(unsigned char), spec);
	ft_add_to_buf((char)va_arg(*arg, int), &spec->buffer);
	if (spec->min_width && spec->minus)
		ft_put_width(sizeof(unsigned char), spec);
}
