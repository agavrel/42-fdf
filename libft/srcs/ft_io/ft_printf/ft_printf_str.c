/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:29:36 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/14 06:01:08 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convertedlen(wchar_t *t, long long precision)
{
	long long		len;
	long long		final_len;
	int				msb;

	len = 0;
	if (precision < 0)
		precision = ft_wcslen(t) * 4;
	while (*t && len <= precision)
	{
		final_len = len;
		msb = ft_printf_msb_find(*t);
		if (msb > 16)
			len += 4;
		else if (msb > 11)
			len += 3;
		else if (msb > 7)
			len += 2;
		else
			len += 1;
		t++;
	}
	if (len <= precision)
		return (len);
	return (final_len);
}

static void	wchar_star(t_buf *buf, t_format *info, \
			wchar_t *t)
{
	char	mychar[5];
	int		i;
	int		len;
	int		charlen;

	i = 0;
	charlen = 0;
	len = convertedlen(t, info->precision);
	if (!(ft_strchr(info->flags, '-')))
		ft_printf_padding(buf, info, len);
	while (i < len)
	{
		ft_bzero(mychar, 5);
		ft_printf_charadd(info, *t, mychar, &charlen);
		if (!(ft_printf_buf_add(buf, mychar, charlen)))
			exit(-1);
		i += charlen;
		t++;
	}
	if (ft_strchr(info->flags, '-'))
		ft_printf_padding(buf, info, len);
}

static void	char_star(t_buf *buf, t_format *info, char *t)
{
	int		len;

	len = ft_strlen(t);
	if (info->precision >= 0)
		len = (info->precision > len ? len : info->precision);
	if (ft_strchr(info->flags, '-'))
	{
		if (!(ft_printf_buf_add(buf, t, len)))
			exit(-1);
		ft_printf_padding(buf, info, len);
	}
	else
	{
		ft_printf_padding(buf, info, len);
		if (!(ft_printf_buf_add(buf, t, len)))
			exit(-1);
	}
}

void		ft_printf_strman(t_buf *buf, t_format *info, wchar_t *t)
{
	if (!t)
		char_star(buf, info, "(null)");
	else
	{
		if (ft_strchr(info->flags, 'l'))
			wchar_star(buf, info, t);
		else
			char_star(buf, info, (char*)t);
	}
}
