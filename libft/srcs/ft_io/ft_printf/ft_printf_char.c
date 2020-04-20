/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 18:05:00 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/18 22:29:58 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	unicode(wchar_t t, char *mychar, int *i, int msb)
{
	if (msb > 7)
	{
		if (msb > 11)
		{
			if (msb > 16)
			{
				mychar[(*i)++] = (0b11110000 | (0b00000111 & (t >> 18)));
				mychar[(*i)++] = (0b10000000 | (0b00111111 & (t >> 12)));
			}
			else
				mychar[(*i)++] = (0b11100000 | (0b00001111 & (t >> 12)));
			mychar[(*i)++] = (0b10000000 | (0b00111111 & (t >> 6)));
		}
		else
			mychar[(*i)++] = (0b11000000 | (0b00011111 & (t >> 6)));
		mychar[(*i)++] = (0b10000000 | (0b00111111 & t));
	}
	else
		mychar[(*i)++] = (char)t;
}

int			ft_printf_msb_find(int t)
{
	int		i;

	i = 0;
	while (t >> i)
		i++;
	return (i);
}

void		ft_printf_charadd(t_format *info, wchar_t t, char *mychar, int *i)
{
	*i = 0;
	if (ft_strchr(info->flags, 'l'))
	{
		if (t < 0 || t > MAX_UNICODE)
			mychar[(*i)++] = '?';
		else
			unicode(t, mychar, i, ft_printf_msb_find(t));
	}
	else
	{
		if (!ft_isascii((char)t))
			mychar[(*i)++] = '?';
		else
			mychar[(*i)++] = (char)t;
	}
}

void		ft_printf_charman(t_buf *buf, t_format *info, wchar_t t)
{
	char	mychar[5];
	int		i;

	ft_bzero(mychar, 5);
	ft_printf_charadd(info, t, mychar, &i);
	if (ft_strchr(info->flags, '-'))
	{
		if (!(ft_printf_buf_add(buf, mychar, i)))
			exit(-1);
		ft_printf_padding(buf, info, i);
	}
	else
	{
		ft_printf_padding(buf, info, i);
		if (!(ft_printf_buf_add(buf, mychar, i)))
			exit(-1);
	}
}
