/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:32:20 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/13 18:07:47 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

const char	*ft_handle_conversion(const char *format, va_list *arg, t_arg *spec)
{
	
	if (ft_strchr("DOUCS", *format))
		spec->size = l;

	return (format);
}
