/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specification.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 21:32:34 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/11 21:45:18 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_parse_flags(char *format, t_arg *spec)
{
	while(ft_strchr("-0+ #", *str))
	{
		if (*str == '-')
			spec->minus = 1;
		else if (*str == '0')
			spec->zero = 1;
		else if (*str == '+')
			spec->plus = 1;
		else if (*str == ' ')
			spec->space = 1;
		else if (*str == '#')
			spec->hash = 1;
		++str;
	}
	return (str);
}
