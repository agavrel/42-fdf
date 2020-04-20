/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:28:53 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/09 16:47:36 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*ch_s;

	ch_s = (const char*)s;
	i = 0;
	while (i < n)
	{
		if (ch_s[i] == (char)c)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
