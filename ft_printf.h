/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:07:42 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/12 20:26:21 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define P_BUFF_SIZE 64

enum				e_size
{
	NONE, HH, H, LL, L, J, Z
};

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
	enum e_size		size;
	\
	struct s_buffer	buffer;
}					t_arg;

int					ft_printf(const char *format, ...);
void				ft_add_to_buf(const char c, struct s_buffer *buffer);

char				*
ft_parse_flags(const char *format, t_arg *spec);
char				*
ft_parse_min_width(const char *format, va_list *arg, t_arg *spec);
char				*
ft_parse_precision(const char *format, va_list *arg, t_arg *spec);
char				*
ft_parse_size(const char *format, t_arg *spec);
char				*
ft_handle_conversion(const char *format, va_list *arg, t_arg *spec);

#endif
