/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:41:15 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/15 10:01:23 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void		ft_add_to_buf(const char c, struct s_buffer *buffer)
{
	buffer->buf[buffer->size] = c;
	++buffer->size;
	if (buffer->size == P_BUFF_SIZE)
	{
		write(STDOUT_FILENO, buffer->buf, buffer->size);
		buffer->written += buffer->size;
		buffer->size = 0;
	}
}
