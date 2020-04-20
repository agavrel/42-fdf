/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:17:06 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/09 16:47:56 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*ch_b;

	ch_b = (char*)b;
	i = 0;
	while (i < len)
	{
		ch_b[i] = (char)c;
		i++;
	}
	return (b);
}
