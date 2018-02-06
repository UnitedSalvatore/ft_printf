/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:03:07 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/06 14:16:43 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "linft.h"

static int	ft_vprintf(const char *format, va_list *arg, t_arg *spec, s)
{
	
	while (*format)
	{
		
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	t_arg	spec;
	size_t	done;

	if (format == NULL || BUFF_SIZE < 1)
		return (-1);
	done = 0;
	va_start(arg, format);
	ft_memset(&spec, 0, sizeof(spec));
	done = ft_vprintf(format, &arg, &spec, &done);
	va_end(arg);
	return (done);
}
