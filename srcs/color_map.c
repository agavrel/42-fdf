/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:23:45 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/25 17:03:11 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

/*
** ssaw : 0 = spring, 1 = summer, 2 = autumn, 3 = winter.
** level : 0 lowest, 3 highest.
*/

static	unsigned	season(int ssaw, int level, int loop)
{
	unsigned season[4][6];

	while (++loop < 4)
	{
		season[loop][0] = MIDNIGHT_BLUE;
		season[loop][5] = WHITE;
	}
	season[0][1] = NICE_BLUE;
	season[0][2] = LAWN_GREEN;
	season[0][3] = GREEN;
	season[0][4] = BROWN;
	season[1][1] = CYAN;
	season[1][2] = NICE_BLUE;
	season[1][3] = RED;
	season[1][4] = CRIMSON;
	season[2][1] = LAWN_GREEN;
	season[2][2] = GREEN;
	season[2][3] = RED;
	season[2][4] = GOLD;
	season[3][1] = NICE_BLUE;
	season[3][2] = WHITE;
	season[3][3] = SKY_BLUE;
	season[3][4] = NICE_BLUE;
	return (season[ssaw][level]);
}

/*
** Shiki no Uta ~ colors map using above function
*/

void				original_color(t_3d *d)
{
	t_index		i;

	i.y = 0;
	while (i.y < d->max.y)
	{
		i.x = -1;
		while (++i.x < d->max.x)
			d->cm[i.y][i.x] = d->c[i.y][i.x];
		++i.y;
	}
}

void				color_map(t_3d *d)
{
	t_index		i;
	float		range;

	range = d->z_max - d->z_min;
	i.y = 0;
	while (i.y < d->max.y)
	{
		i.x = -1;
		while (++i.x < d->max.x)
		{
			if (d->m[i.y][i.x].z < 0)
				d->cm[i.y][i.x] = (d->m[i.y][i.x].z < -50) ?
				season(d->season, 0, -1) : season(d->season, 1, -1);
			else if (d->m[i.y][i.x].z < (0.40 * d->z_max))
				d->cm[i.y][i.x] = (d->m[i.y][i.x].z < (0.20 * d->z_max)) ?
					season(d->season, 2, -1) : season(d->season, 3, -1);
			else
				d->cm[i.y][i.x] = (d->m[i.y][i.x].z < 0.60 * d->z_max) ?
				season(d->season, 4, -1) : season(d->season, 5, -1);
		}
		++i.y;
	}
}
