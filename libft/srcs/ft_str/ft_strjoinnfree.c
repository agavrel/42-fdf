/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinnfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:24:26 by agrumbac          #+#    #+#             */
/*   Updated: 2017/03/08 02:44:24 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinnfree(char *s1, char *s2, size_t len, char free12b)
{
	char	*s;
	char	*ret;
	char	*tmp1;
	char	*tmp2;

	if (!(s = ft_strnew(ft_strlen(s1) + len + 1)))
		return (NULL);
	ret = s;
	tmp1 = s1;
	tmp2 = s2;
	while (*s1)
		*s++ = *s1++;
	while (*s2 && len--)
		*s++ = *s2++;
	if (free12b == '1' || free12b == 'b')
		free(tmp1);
	if (free12b == '2' || free12b == 'b')
		free(tmp2);
	return (ret);
}
