/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:32:20 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/21 14:13:38 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static t_handler	ft_get_handler(t_handler handlers[], int num)
{
	handlers[0] = &ft_handle_string;
	handlers[1] = &ft_handle_wstring;
	handlers[2] = &ft_handle_pointer;
	handlers[3] = &ft_handle_int;
	handlers[4] = &ft_handle_int;
	handlers[5] = &ft_handle_int;
	handlers[6] = &ft_handle_o;
	handlers[7] = &ft_handle_o;
	handlers[8] = &ft_handle_u;
	handlers[9] = &ft_handle_u;
	handlers[10] = &ft_handle_x;
	handlers[11] = &ft_handle_x;
	handlers[12] = &ft_handle_char;
	handlers[13] = &ft_handle_wchar;
	handlers[14] = &ft_handle_char;
	return (handlers[num]);
}

const char			*ft_handle_conversion(
	const char *format,
	va_list *arg,
	t_arg *spec
)
{
	const char	conversion_str[] = "sSpdDioOuUxXcC%";
	const char	*conversion_char;
	t_handler	handlers[15];
	t_handler	handler;

	conversion_char = ft_strchr(conversion_str, *format);
	if (conversion_char && *conversion_char)
	{
		if (ft_strchr("DOUCS", *format))
			spec->size = L;
		handler = ft_get_handler(handlers, conversion_char - conversion_str);
		handler(format, arg, spec);
		++format;
	}
	return (format);
}
