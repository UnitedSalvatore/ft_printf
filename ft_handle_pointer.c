/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:02:23 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/21 11:58:27 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdarg.h>
#include "ft_printf.h"

void	ft_handle_pointer(const char *format, va_list *arg, t_arg *spec)
{
	spec->hash = 1;
	spec->size = L;
	return (ft_handle_x(format, arg, spec));
}
