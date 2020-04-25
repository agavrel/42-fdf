/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:40:46 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/20 23:02:31 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftmath.h"

float	**ft_sum_matrix(float **a, float **b)
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
				m[i.y][i.x] += a[i.y][i.z] + b[i.z][i.x];
				++i.z;
			}
			++i.x;
		}
		++i.y;
	}
	a = m;
	free(m);
	return (a);
}
