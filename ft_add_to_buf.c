/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:41:15 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/17 17:38:37 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void		ft_add_to_buf(const char c, struct s_buffer *buffer)
{
	buffer->buf[buffer->size] = c;
	++buffer->size;
	//ft_putstr(ft_uitoa_base((unsigned char)c, 2));
	//ft_putstr("\n");
	if (buffer->size == P_BUFF_SIZE)
	{
		write(STDOUT_FILENO, buffer->buf, buffer->size);
		buffer->written += buffer->size;
		buffer->size = 0;
	}
}
