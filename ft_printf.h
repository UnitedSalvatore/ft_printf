/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:07:42 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/11 21:35:27 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define P_BUFF_SIZE 64

struct				s_buffer
{
	char			buf[P_BUFF_SIZE];
	int				size;
	int				written;
};

typedef struct		s_arg
{
	int				minus;
	int				zero;
	int				plus;
	int				space;
	int				hash;
	\
	int				min_width;
	int				precision;
	\
	struct s_buffer	buffer;
}					t_arg;

int					ft_printf(const char *format, ...);
void				ft_add_to_buf(const char c, struct s_buffer *buffer);
char				*ft_parse_flags(format, spec);

#endif
