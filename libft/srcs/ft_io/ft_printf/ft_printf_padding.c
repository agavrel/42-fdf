/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 03:35:20 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/14 05:55:08 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_padding(t_buf *buf, t_format *info, long long len)
{
	while (len < info->width)
	{
		if (ft_strchr(info->flags, '0') && !(ft_strchr(FT_PRINTF_INT_TYPES, \
			info->type) && info->precision > 0) && \
			!(ft_strchr(info->flags, '-')))
		{
			if (!(ft_printf_buf_add(buf, "0", 1)))
				exit(-1);
		}
		else
		{
			if (!(ft_printf_buf_add(buf, " ", 1)))
				exit(-1);
		}
		len++;
	}
}

void	ft_printf_precision_int(t_buf *buf, t_format *info, \
		long long len)
{
	while (len < info->precision)
	{
		if (!(ft_printf_buf_add(buf, "0", 1)))
			exit(-1);
		len++;
	}
}
