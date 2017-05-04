/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factor_matrix_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:57:19 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/22 13:34:50 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftmath.h"

float	**ft_factor_matrix_free(float **a, float **b, char free)
{
	float	**m;
	t_i		i;

	m = ft_identity_matrix(0, 0);
	i.y = 0;
	while (i.y < 4)
	{
		i.x = 0;
		while (i.x < 4)
		{
			i.z = 0;
			while (i.z < 4)
			{
				m[i.y][i.x] += a[i.y][i.z] * b[i.z][i.x];
				++i.z;
			}
			++i.x;
		}
		++i.y;
	}
	(free == 'L' || free == 'B') ? ft_free_matrix(a) : 0;
	(free == 'R' || free == 'B') ? ft_free_matrix(b) : 0;
	return (m);
}
