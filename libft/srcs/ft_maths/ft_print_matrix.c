/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:46:02 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/20 23:01:20 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftmath.h"
#include <stdio.h>

void	ft_print_matrix(float **m)
{
	t_i	i;

	i.y = 0;
	while (++i.y < 4)
	{
		i.x = 0;
		while (++i.x < 4)
		{
			if (!(m[i.y][i.x] - (int)m[i.y][i.x]))
				printf("%.0f.0   ", m[i.y][i.x]);
			else
				printf("%.1f   ", m[i.y][i.x]);
			++i.x;
		}
		printf("\n");
		++i.y;
	}
}
