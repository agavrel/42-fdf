/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:27:35 by angavrel          #+#    #+#             */
/*   Updated: 2016/11/10 16:04:20 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ((char)c))
			ptr = ((char*)&s[i]);
		i++;
	}
	if (s[i] == ((char)c))
		ptr = ((char*)&s[i]);
	return (ptr);
}
