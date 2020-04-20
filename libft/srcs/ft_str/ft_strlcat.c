/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:04:58 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/07 17:40:20 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static size_t	ft_strlen_l(const char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < size)
	{
		i++;
	}
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	dstlen = ft_strlen_l(dst, size);
	i = 0;
	while (src[i] && (i + dstlen + 1) < size)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (dstlen - size > 0)
		dst[dstlen + i] = '\0';
	return (dstlen + ft_strlen(src));
}
