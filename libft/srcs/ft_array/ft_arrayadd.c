/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:30:39 by agrumbac          #+#    #+#             */
/*   Updated: 2017/02/18 02:57:54 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arraygrow(t_array *array)
{
	void		*tmp;

	if (!array)
		return (0);
	tmp = array->content;
	array->content = ft_memalloc(array->typesize * (array->arraysize * 2));
	if (!(array->content))
		return (0);
	ft_memcpy(array->content, tmp, (array->typesize * array->arraysize));
	array->arraysize *= 2;
	free(tmp);
	return (1);
}

t_array		*ft_arrayadd(t_array *array, void *new, unsigned long long index, \
			unsigned int size)
{
	if (!new || !array)
		return (NULL);
	while (array->arraysize - (index * array->typesize) < \
			(size * array->typesize))
		if (!(ft_arraygrow(array)))
			return (NULL);
	ft_memcpy(array->content + (index * array->typesize), new, \
		size * array->typesize);
	return (array);
}
