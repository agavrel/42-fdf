/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 03:31:16 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/22 03:34:04 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftmath.h"

float	**ft_copy_matrix(float **m)
{
	float	**copy;
	t_i		i;

	if (!(copy = (float**)malloc(sizeof(float*) * 4)))
		return (0);
	i.y = 0;
	while (i.y < 4)
	{
		if (!(copy[i.y] = (float*)malloc(sizeof(float) * 4)))
			return (0);
		i.x = 0;
		while (i.x < 4)
		{
			copy[i.y][i.x] = m[i.y][i.x];
			++i.x;
		}
		++i.y;
	}
	return (copy);
}
