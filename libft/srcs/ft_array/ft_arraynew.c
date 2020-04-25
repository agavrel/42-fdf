/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:27:08 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/27 00:16:47 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array		*ft_arraynew(size_t typesize)
{
	t_array	*array;

	if (!(array = ft_memalloc(sizeof(t_array))))
		return (NULL);
	if (!(array->content = ft_memalloc(typesize * ARRAY_SIZE)))
		return (NULL);
	array->typesize = typesize;
	array->arraysize = ARRAY_SIZE;
	return (array);
}
