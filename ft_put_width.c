/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 03:31:40 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/23 06:18:12 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_width(int data_size, t_arg *spec)
{
	if (spec->zero)
		while (spec->min_width > data_size++)
			ft_add_to_buf('0', &spec->buffer);
	else
		while (spec->min_width > data_size++)
			ft_add_to_buf(' ', &spec->buffer);
}
