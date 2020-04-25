/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:34:52 by angavrel          #+#    #+#             */
/*   Updated: 2016/11/18 17:55:30 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, char control)
{
	char	*mem;

	mem = ft_strjoin(s1, s2);
	if (control == 'L' || control == 'B')
		free(s1);
	if (control == 'R' || control == 'B')
		free(s2);
	return (mem);
}
