/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 15:39:45 by angavrel          #+#    #+#             */
/*   Updated: 2016/11/27 22:21:34 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	i;
	size_t	n;
	size_t	m;

	n = ft_strlen(dest);
	m = ft_strlen(src);
	i = 0;
	while (*src && (i + n < size - 1))
		dest[i++ + n] = *src++;
	dest[i + n] = '\0';
	return (m += n < size ? n : size);
}
