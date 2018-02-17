/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:07:42 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/17 18:53:37 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "stdio.h"
# include "libft.h"

# define P_BUFF_SIZE 64
# define MIN_WIDTH

enum				e_size
{
	NONE, HH, H, LL, L, J, Z
};

struct				s_buffer
{
	char			buf[P_BUFF_SIZE];
	size_t			size;
	size_t			written;
};

typedef struct		s_arg
{
	int				minus : 1;
	int				zero : 1;
	int				plus : 1;
	int				space : 1;
	int				hash : 1;
	\
	int				min_width;
	int				is_precision : 1;
	int				precision;
	enum e_size		size;
	\
	struct s_buffer	buffer;
}					t_arg;

typedef void		(*t_handler)(const char *, va_list*, t_arg*);

int					ft_printf(const char *format, ...);
void				ft_add_to_buf(const char c, struct s_buffer *buffer);
void				ft_put_width(int data_size, t_arg *spec);

const char			*
ft_parse_flags(const char *format, t_arg *spec);
const char			*
ft_parse_min_width(const char *format, va_list *arg, t_arg *spec);
const char			*
ft_parse_precision(const char *format, va_list *arg, t_arg *spec);
const char			*
ft_parse_size(const char *format, t_arg *spec);
const char			*
ft_handle_conversion(const char *format, va_list *arg, t_arg *spec);

void				ft_handle_char(const char *format, va_list *arg, t_arg *spec);
void				ft_handle_int(const char *format, va_list *arg, t_arg *spec);

void				ft_print_specification(t_arg *spec);

#endif
