/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:03:07 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/11 00:46:24 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

// static t_arg	*ft_default_arg(t_arg *spec)
// {

// }

static void		ft_parse_arg(const char **format, va_list *arg, t_arg *spec)
{
	++*format;
	arg = (void *)arg;
	spec = (void *)spec;
}

static int		ft_vprintf(const char *format, va_list *arg, t_arg *spec)
{
	while (*format)
	{
		if (*format == '%')
		{
	//		ft_default_arg(spec);
			ft_parse_arg(&format, arg, spec);
		}
		else
			ft_add_to_buf(*format, spec);
		++format;
	}
	ft_add_to_buf('\0', spec);
	return (spec->written);
}

int				ft_printf(const char *format, ...)
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
