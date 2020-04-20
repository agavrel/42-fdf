/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:35:12 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/18 16:28:04 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ch_dst;
	unsigned char	*ch_src;

	i = 0;
	ch_dst = (unsigned char*)dst;
	ch_src = (unsigned char*)src;
	while (ch_src < ch_dst && i < len)
	{
		ch_dst[len - 1] = ch_src[len - 1];
		len--;
	}
	while (ch_src > ch_dst && i < len)
	{
		ch_dst[i] = ch_src[i];
		i++;
	}
	return (dst);
}
