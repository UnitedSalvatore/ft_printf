/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:41:15 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/06 18:30:39 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putbuf(const char c, t_arg spec, const int forced_print_flag)
{
	if (forced_print_flag && spec->size > 0)
	{
		write(STDOUT_FILENO, &spec->buf, spec->size);
		spec->size = 0;
	}
	else
	{
		(spec->buf)[spec->size] = c;
		++spec->size;
		if (spec->size == BUFF_SIZE)
		{
			write(STDOUT_FILENO, &spec->buf, spec->size);
			spec->size = 0;
		}
	}
}