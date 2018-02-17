/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:32:20 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/17 18:19:53 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static t_handler	ft_get_handler(t_handler handlers[], int num)
{
	handlers[0] = 0;
	handlers[1] = 0;
	handlers[2] = 0;
	handlers[3] = &ft_handle_int;
	handlers[4] = 0;
	handlers[5] = &ft_handle_int;
	handlers[6] = 0;
	handlers[7] = 0;
	handlers[8] = 0;
	handlers[9] = 0;
	handlers[10] = 0;
	handlers[11] = 0;
	handlers[12] = &ft_handle_char;
	handlers[13] = &ft_handle_char;
	handlers[14] = 0;
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
// Убери нахер эту проверку, как доделаешь, чмоки :*
		if (handler)
			handler(format, arg, spec);
		++format;
	}
	return (format);
}
