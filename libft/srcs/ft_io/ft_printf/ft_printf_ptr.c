/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:43:10 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/14 05:55:41 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptrmanleft(t_buf *buf, t_format *info, \
				unsigned long t)
{
	size_t	len;
	char	ptr[MAX_LL_LEN];

	ft_bzero(ptr, MAX_LL_LEN);
	ft_printf_itoa(t, 16, ptr);
	ft_strtolower(ptr);
	len = ft_strlen(ptr);
	if (!(ft_printf_buf_add(buf, "0x", 2)))
		exit(-1);
	if (!(ft_printf_buf_add(buf, ptr, len)))
		exit(-1);
	ft_printf_padding(buf, info, len + 2);
}

void			ft_printf_ptrman(t_buf *buf, t_format *info, \
				unsigned long t)
{
	size_t	len;
	char	ptr[MAX_LL_LEN];

	if (ft_strchr(info->flags, '-'))
		ptrmanleft(buf, info, t);
	else
	{
		ft_bzero(ptr, MAX_LL_LEN);
		ft_printf_itoa(t, 16, ptr);
		ft_strtolower(ptr);
		len = ft_strlen(ptr);
		if (!(ft_strchr(info->flags, '0')))
			ft_printf_padding(buf, info, len + 2);
		if (!(ft_printf_buf_add(buf, "0x", 2)))
			exit(-1);
		if (ft_strchr(info->flags, '0'))
			ft_printf_padding(buf, info, len + 2);
		if (!(ft_printf_buf_add(buf, ptr, len)))
			exit(-1);
	}
}
