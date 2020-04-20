/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:34:52 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/18 17:55:30 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	if (!(new = (char*)malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	new[len] = '\0';
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	len = i;
	i = 0;
	while (s2[i])
	{
		new[len + i] = s2[i];
		i++;
	}
	return (new);
}
