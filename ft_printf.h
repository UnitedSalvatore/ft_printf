/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:07:42 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/10 17:30:26 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define P_BUFF_SIZE 64

typedef struct	s_arg
{
	int		zero_pad;
	int		sign_pad;
	int		left_pad;

	char	buf[P_BUFF_SIZE];
	int		size;
	int		written;
}				t_arg;

int		ft_printf(const char *format, ...);
void	ft_add_to_buf(const char c, t_arg *spec);

#endif
