/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:41:15 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/10 17:29:45 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static void	ft_putbuff(t_arg *spec)
{
			write(STDOUT_FILENO, spec->buf, spec->size);
			spec->written += spec->size;
			spec->size = 0;
}

void		ft_add_to_buf(const char c, t_arg *spec)
{
	if (c)
	{
		spec->buf[spec->size] = c;
		++spec->size;
		if (spec->size == P_BUFF_SIZE)
			ft_putbuff(spec);
	}
	else
		ft_putbuff(spec);
}
