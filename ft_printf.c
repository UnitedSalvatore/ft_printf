/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:03:07 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/15 10:04:19 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

static t_arg		*ft_default_arg(t_arg *spec)
{
	spec->minus = 0;
	spec->zero = 0;
	spec->plus = 0;
	spec->space = 0;
	spec->hash = 0;
	spec->min_width = 0;
	spec->is_precision = 0;
	spec->precision = 0;
	spec->size = NONE;
	return (spec);
}

static const char	*ft_parse_arg(const char *format, va_list *arg, t_arg *spec)
{
	format = ft_parse_flags(format, spec);
	format = ft_parse_min_width(format, arg, spec);
	format = ft_parse_precision(format, arg, spec);
	format = ft_parse_size(format, spec);
	format = ft_handle_conversion(format, arg, spec);
	//ft_print_specification(spec);
	return (format);
}

static size_t		ft_vprintf(const char *format, va_list *arg, t_arg *spec)
{
	while (*format)
	{
		if (*format == '%')
		{
			ft_default_arg(spec);
			format = ft_parse_arg(++format, arg, spec);
		}
		else
			ft_add_to_buf(*format++, &spec->buffer);
	}
	write(STDOUT_FILENO, spec->buffer.buf, spec->buffer.size);
	spec->buffer.written += spec->buffer.size;
	spec->buffer.size = 0;
	return (spec->buffer.written);
}

int					ft_printf(const char *format, ...)
{
	va_list	arg;
	t_arg	spec;
	int		done;

	if (format == NULL || BUFF_SIZE < 1)
		return (-1);
	va_start(arg, format);
	ft_memset(&spec, 0, sizeof(spec));
	done = (int)ft_vprintf(format, &arg, &spec);
	va_end(arg);
	return (done);
}
