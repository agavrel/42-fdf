/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 08:03:54 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/14 05:53:12 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			typesizer(t_format *info)
{
	if (info->type == 'd' || info->type == 'i')
		info->base = 10;
	else if (info->type == 'x' || info->type == 'X')
		info->base = 16;
	else if (info->type == 'o')
		info->base = 8;
	else if (info->type == 'b')
		info->base = 2;
	else if (info->type == 'u')
		info->base = -10;
}

static void			conversion_ouxx(char *numb, t_format *info, long long t)
{
	if (ft_strchrn(info->flags, 'l') == 2)
		ft_printf_itoa((unsigned long long)t, info->base, numb);
	else if (ft_strchr(info->flags, 'l'))
		ft_printf_itoa((unsigned long)t, info->base, numb);
	else if (ft_strchrn(info->flags, 'h') == 2)
		ft_printf_itoa((unsigned char)t, info->base, numb);
	else if (ft_strchr(info->flags, 'h'))
		ft_printf_itoa((unsigned short)t, info->base, numb);
	else if (ft_strchr(info->flags, 'j'))
		ft_printf_itoa((__uintmax_t)t, info->base, numb);
	else if (ft_strchr(info->flags, 'z'))
		ft_printf_itoa((size_t)t, info->base, numb);
	else
		ft_printf_itoa((unsigned int)t, info->base, numb);
	if (info->type == 'x')
		ft_strtolower(numb);
}

static void			conversion(char *numb, t_format *info, long long t)
{
	typesizer(info);
	if (info->type != 'd' && info->type != 'i')
		conversion_ouxx(numb, info, t);
	else if (ft_strchrn(info->flags, 'l') == 2)
		ft_printf_itoa((long long)t, info->base, numb);
	else if (ft_strchr(info->flags, 'l'))
		ft_printf_itoa((long)t, info->base, numb);
	else if (ft_strchrn(info->flags, 'h') == 2)
		ft_printf_itoa((signed char)t, info->base, numb);
	else if (ft_strchr(info->flags, 'h'))
		ft_printf_itoa((short)t, info->base, numb);
	else if (ft_strchr(info->flags, 'j'))
		ft_printf_itoa((__intmax_t)t, info->base, numb);
	else if (ft_strchr(info->flags, 'z'))
		ft_printf_itoa((signed long)t, info->base, numb);
	else
		ft_printf_itoa((int)t, info->base, numb);
}

static void			signman(t_format *info, char *sign, char *numb, int *i)
{
	ft_bzero(sign, 5);
	if ((*i = 0) || (info->type == 'd' || info->type == 'i'))
	{
		if (numb[0] == '-')
			sign[(*i)++] = '-';
		else if (ft_strchr(info->flags, '+'))
			sign[(*i)++] = '+';
		else if (ft_strchr(info->flags, ' '))
			sign[(*i)++] = ' ';
	}
	else if (ft_strchr(info->flags, '#') && !(!numb[1] && numb[0] == '0' \
	&& info->precision != 0) && !(info->base == 16 && !(info->precision)))
	{
		if (info->type == 'x')
			ft_strncpy(sign, "0x", 2);
		else if (info->type == 'X')
			ft_strncpy(sign, "0X", 2);
		else if (info->type == 'b')
			ft_strncpy(sign, "0b", 2);
		else if (info->type == 'o')
			ft_strncpy(sign, "0", 2);
		*i = (info->type == 'o' ? 1 : 2);
	}
}

void				ft_printf_intman(t_buf *buf, t_format *info, long long t)
{
	int				len;
	char			numb[MAX_LL_LEN];
	char			sign[5];
	int				i;

	conversion(numb, info, t);
	signman(info, sign, numb, &i);
	if ((len = 0) || !(info->precision == 0 && t == 0))
		len = (sign[0] == '-' ? ft_strlen(numb) - 1 : ft_strlen(numb));
	if (!(ft_strchr(info->flags, '-')) && !(ft_strchr(info->flags, '0') && \
	info->precision < 0))
		ft_printf_padding(buf, info, i + info->precision > len ? \
		info->precision: len);
	if (!(ft_printf_buf_add(buf, sign, i)))
		exit(-1);
	if (!(ft_strchr(info->flags, '-')) && ft_strchr(info->flags, '0') && \
	info->precision < 0)
		ft_printf_padding(buf, info, i + info->precision > len ? \
		info->precision : len);
	ft_printf_precision_int(buf, info, len);
	if (!(ft_printf_buf_add(buf, &(numb[(sign[0] == '-' ? 1 : 0)]), len)))
		exit(-1);
	if (ft_strchr(info->flags, '-'))
		ft_printf_padding(buf, info, i + info->precision > len ? \
		info->precision : len);
}
