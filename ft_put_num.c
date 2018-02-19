/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:56:03 by ypikul            #+#    #+#             */
/*   Updated: 2018/02/19 21:05:24 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static size_t	int_len(intmax_t num)
{
	size_t i;

	i = 1;
	if (num < 0)
		i++;
	while (num /= 10)
		i++;
	return (i);
}

char			*ft_itoa(intmax_t num)
{
	size_t		len;
	char		*str;
	n2;

	len = int_len(n);
	if (n < 0)
	{
		*str = '-';
		n2 = -n2;
	}
	str[--len] = (char)(n2 % 10 + 48);
	while (n2 /= 10)
		str[--len] = (char)(n2 % 10 + 48);
	return (str);
}



void	ft_handle_num(t_arg *spec, uintmax_t num, int base, const char *prefix)
{
	char		buf[sizeof(intmax_t) * sizeof(char)];
	char		*p;
	const char	digits[] = "0123456789abcdefABCDEF";

	p = &buf[sizeof(intmax_t) * sizeof(char) - 1];
	*p-- = digits[num % base];
	while (num %= base)
		*p-- = digits[num % base];
}