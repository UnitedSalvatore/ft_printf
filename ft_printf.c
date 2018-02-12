/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:03:07 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/12 20:59:33 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

static const char	*\
ft_parse_arg(const char *format, va_list *arg, t_arg *spec)
{
	format = ft_parse_flags(format, spec);
	format = ft_parse_min_width(format, arg, spec);
	format = ft_parse_precision(format, arg, spec);
	format = ft_parse_size(format, spec);
	format = ft_handle_conversion(format, arg, spec);
	return (format);
}

static int			\
ft_vprintf(const char *format, va_list *arg, t_arg *spec)
{
	while (*format)
	{
		if (*format == '%')
		{
			ft_default_arg(spec);
			format = ft_parse_arg(++format, arg, spec);
		}
		else
			ft_add_to_buf(*format, &spec->buffer);
		++format;
	}
	ft_add_to_buf('\0', &spec->buffer);
	return (spec->buffer.written);
}

int					\
ft_printf(const char *format, ...)
{
	va_list	arg;
	t_arg	spec;
	int		done;

	if (format == NULL || BUFF_SIZE < 1)
		return (-1);
	va_start(arg, format);
	ft_memset(&spec, 0, sizeof(spec));
	done = ft_vprintf(format, &arg, &spec);
	va_end(arg);
	return (done);
}
