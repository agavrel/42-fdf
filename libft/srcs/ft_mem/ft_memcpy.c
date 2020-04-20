/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:03:28 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/09 16:33:20 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ch_dst;
	const char	*ch_src;

	ch_dst = (char*)dst;
	ch_src = (const char*)src;
	i = 0;
	while (i < n)
	{
		ch_dst[i] = ch_src[i];
		i++;
	}
	return (dst);
}
