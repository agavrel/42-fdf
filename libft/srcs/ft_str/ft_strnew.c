/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:34:12 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/10 15:55:26 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

char		*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char*)malloc(size + 1)))
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
