/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:57:05 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/10 16:22:37 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ch_dst;
	const unsigned char	*ch_src;

	ch_dst = (unsigned char*)dst;
	ch_src = (const unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ch_dst[i] = ch_src[i];
		if ((unsigned char)c == ch_src[i])
			return (dst + (i + 1));
		i++;
	}
	return (NULL);
}
