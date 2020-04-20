/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:48:04 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/10 16:27:17 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ch_s;

	ch_s = (char*)s;
	i = 0;
	while (i < n)
	{
		ch_s[i] = '\0';
		i++;
	}
}

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = (void*)malloc(size)))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
