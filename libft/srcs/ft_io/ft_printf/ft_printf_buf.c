/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 10:46:30 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/18 22:32:16 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_buf_add(t_buf *buf, void *new, size_t size)
{
	int			diff;
	long long	new_i;

	new_i = 0;
	while (FT_PRINTF_BUF_SIZE - buf->index < (int)size)
	{
		diff = FT_PRINTF_BUF_SIZE - buf->index;
		ft_memcpy(&(buf->content[buf->index]), (new + new_i), diff);
		size -= diff;
		new_i += diff;
		buf->index += diff;
		buf->ret += diff;
		if (write(FT_PRINTF_FD, buf->content, buf->index) < 0)
			return (0);
		buf->index = 0;
	}
	ft_memcpy(&(buf->content[buf->index]), (new + new_i), size);
	buf->index += size;
	buf->ret += size;
	return (1);
}

int				ft_printf_buf_end(t_buf *buf)
{
	if (write(FT_PRINTF_FD, buf->content, buf->index) < 0)
		return (0);
	return (1);
}
