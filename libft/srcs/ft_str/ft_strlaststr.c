/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlaststr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:22:38 by agrumbac          #+#    #+#             */
/*   Updated: 2017/02/11 15:30:22 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlaststr(const char *big, const char *little)
{
	char		*found;
	char		*look;

	found = NULL;
	look = NULL;
	while (*big)
	{
		if ((look = ft_strstr(big, little)))
			found = look;
		big++;
	}
	return (found);
}
