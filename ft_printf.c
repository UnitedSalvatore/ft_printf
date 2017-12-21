/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:03:07 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/05 17:47:17 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	ft_vprintf(const char *format, va_list *arg, s)
{
	while (*format)
	{
		
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	done;

	if (format == NULL)
		return (-1);
	done = 0;
	va_start(arg, format);
	done = ft_vprintf(format, &arg, &done);
	va_end(arg);
	return (done);
}
