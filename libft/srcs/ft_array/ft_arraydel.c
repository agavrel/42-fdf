/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:31:15 by agrumbac          #+#    #+#             */
/*   Updated: 2016/12/27 00:17:15 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arraydel(t_array **array)
{
	if (array && *array)
	{
		if (((t_array*)(*array))->content)
			free(((t_array*)(*array))->content);
		free(*array);
		*array = NULL;
	}
}
