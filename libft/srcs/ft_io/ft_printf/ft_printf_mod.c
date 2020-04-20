/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 18:00:26 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/14 05:54:43 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_modman(t_buf *buf, t_format *info)
{
	if (ft_strchr(info->flags, '-'))
	{
		if (!(ft_printf_buf_add(buf, &(info->type), 1)))
			exit(-1);
		ft_printf_padding(buf, info, 1);
	}
	else
	{
		ft_printf_padding(buf, info, 1);
		if (!(ft_printf_buf_add(buf, &(info->type), 1)))
			exit(-1);
	}
}
