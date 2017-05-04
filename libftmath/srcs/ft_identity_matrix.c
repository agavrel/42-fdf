/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identity_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:20:36 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/22 12:21:34 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftmath.h"

float	**ft_identity_matrix(int fill, int fill_diagonal)
{
	float	**m;
	t_i		i;

	if (!(m = (float**)malloc(sizeof(float*) * 4)))
		return (0);
	i.y = 0;
	while (i.y < 4)
	{
		if (!(m[i.y] = (float*)malloc(sizeof(float) * 4)))
			return (0);
		i.x = 0;
		while (i.x < 4)
		{
			m[i.y][i.x] = (i.x != i.y) ? fill : fill_diagonal;
			++i.x;
		}
		++i.y;
	}
	return (m);
}
