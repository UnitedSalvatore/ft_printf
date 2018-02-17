/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specification.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 21:32:34 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/17 20:06:31 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

const char	*ft_parse_flags(const char *format, t_arg *spec)
{
	while (*format && ft_strchr("-0+ #", *format))
	{
		if (*format == '-')
			spec->minus = 1;
		else if (*format == '0')
			spec->zero = 1;
		else if (*format == '+')
			spec->plus = 1;
		else if (*format == ' ')
			spec->space = 1;
		else if (*format == '#')
			spec->hash = 1;
		++format;
	}
	if (spec->minus)
		spec->zero = 0;
	if (spec->plus)
		spec->space = 0;
	return (format);
}

const char	*ft_parse_min_width(const char *format, va_list *arg, t_arg *spec)
{
	if (*format == '*')
	{
		spec->min_width = va_arg(*arg, int);
		if (spec->min_width < 0)
		{
			spec->minus = 1;
			spec->min_width = -spec->min_width;
		}
		++format;
	}
	else
		while (ft_isdigit(*format))
			spec->min_width = spec->min_width * 10 + (*format++ - '0');
	return (format);
}

const char	*ft_parse_precision(const char *format, va_list *arg, t_arg *spec)
{
	if (*format != '.')
		return (format);
	spec->is_precision = 1;
	if (*++format == '*')
	{
		spec->precision = va_arg(*arg, int);
		if (spec->precision < 0)
			spec->is_precision = 0;
		++format;
	}
	else
	{
		spec->precision = 0;
		while (ft_isdigit(*format))
			spec->precision = spec->precision * 10 + (*format++ - '0');
	}
	return (format);
}

const char	*ft_parse_size(const char *format, t_arg *spec)
{
	while (*format && ft_strchr("hljz", *format))
	{
		if (*format == 'h' && *(format + 1) == 'h')
		{
			spec->size = HH;
			++format;
		}
		else if (*format == 'l' && *(format + 1) == 'l')
		{
			spec->size = LL;
			++format;
		}
		else if (*format == 'h')
			spec->size = H;
		else if (*format == 'l')
			spec->size = L;
		else if (*format == 'j')
			spec->size = J;
		else if (*format == 'z')
			spec->size = Z;
		++format;
	}
	return (format);
}
