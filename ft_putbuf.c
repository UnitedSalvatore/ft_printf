/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:41:15 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/08 21:11:07 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putbuf(const char c, t_arg *spec)
{
	if (c)
	{
		spec->buf[spec->size] = c;
		++spec->size;
		if (spec->size == P_BUFF_SIZE)
		{
			write(STDOUT_FILENO, spec->buf, spec->size);
			spec->size = 0;
		}
	}
	else
	{
		write(STDOUT_FILENO, spec->buf, spec->size);
		spec->size = 0;
	}
}
