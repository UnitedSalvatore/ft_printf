/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specification.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 21:32:34 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/12 19:45:44 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

char	*ft_parse_flags(const char *format, t_arg *spec)
{
	while(ft_strchr("-0+ #", *str))
	{
		if (*str == '-')
			spec->minus = 1;
		else if (*str == '0')
			spec->zero = 1;
		else if (*str == '+')
			spec->plus = 1;
		else if (*str == ' ')
			spec->space = 1;
		else if (*str == '#')
			spec->hash = 1;
		++str;
	}
	return (str);
}

char	*ft_parse_min_width(const char *format, va_list *arg, t_arg *spec)
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
			spec->min_width = spec->min_width * 10 + (*format++ - '0')
	return (format);
}

char	*ft_parse_precision(const char *format, va_list *arg, t_arg *spec)
{
	spec->precision = 6;
	if (*format != '.')
		return (format);
	if (*++format == '*')
	{
		spec->precision = va_arg(*arg, int);
		if (spec->precision < 0)
			spec->precision = 6;
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

char	*ft_parse_size(const char *format, t_arg *spec)
{
	while (ft_strchr("hljz", *format))
	{
		if (*format == 'h' && *(format + 1) == 'h')
			spec->size = HH;
		else if (*format == 'h')
			spec->size = H;
		else if (*format == 'l' && *(format + 1) == 'l')
			spec->size = LL;
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