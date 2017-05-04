/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 07:12:01 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/25 17:12:57 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

/*
** storing color in d->c
** we put def_color.x equal to 1 to indicate that we will use color provided
** by the map instead of our own colors. no color is slightly grey
*/

int			ft_ishex(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
			|| (c >= 'A' && c <= 'F'));
}

long		get_colors(t_3d *d)
{
	size_t	n;
	int		c;

	n = 0;
	if (*d->s == '-')
		++d->s;
	while (ft_isdigit(*d->s))
		++d->s;
	if (!*d->s || *(d->s) == ' ')
		return (0xaaaaaa);
	d->s = d->s + 3;
	while (*(d->s + n) && (ft_ishex(*(d->s + n))))
		++n;
	if (!n || !(c = ft_htoi(ft_strndup(d->s, n))))
	{
		d->s += n;
		return (0xaaaaaa);
	}
	d->s += n;
	d->map_had_color = True;
	return (c);
}

/*
** Store ground elevation in d->m[y][x].z and colors into d->c
*/

int			get_depth_and_colors(t_3d *d)
{
	t_index	i;

	d->z_min = 0;
	d->z_max = 0;
	i.y = -1;
	while (++i.y < d->max.y)
	{
		i.x = -1;
		while (++i.x < d->max.x)
		{
			while (*d->s && *d->s == ' ')
				++d->s;
			d->m[i.y][i.x].z = ft_atoi(d->s);
			d->m[i.y][i.x].y = i.y;
			d->m[i.y][i.x].x = i.x;
			d->m[i.y][i.x].z > d->z_max ? d->z_max = d->m[i.y][i.x].z : 0;
			d->m[i.y][i.x].z < d->z_min ? d->z_min = d->m[i.y][i.x].z : 0;
			d->c[i.y][i.x] = get_colors(d);
		}
	}
	return (1);
}

/*
** used to free everything when user push escape.
*/

void		free_all(t_3d *d)
{
	int		i;

	i = 0;
	while (i < d->max.y)
	{
		d->m[i] ? free(d->m[i]) : 0;
		d->c[i] ? free(d->c[i]) : 0;
		d->mm[i] ? free(d->mm[i]) : 0;
		d->cm[i] ? free(d->cm[i]) : 0;
		++i;
	}
	d->m ? free(d->m) : 0;
	d->c ? free(d->c) : 0;
	d->mm ? free(d->mm) : 0;
	d->cm ? free(d->cm) : 0;
}

/*
** Main function parsing before caling fdf
*/

int			main(int ac, char **av)
{
	t_3d	d;
	int		fd;

	if (ac < 2)
		return (ft_error("Usage: ./fdf [File]"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_error("Could not open file"));
	if (!read_map(&d, av[1]))
		return (ft_error("Wrong inputs"));
	if (!malloc_map(&d))
		return (ft_error("Conversion to isometric 3d failed"));
	d.map_had_color = False;
	if (!get_depth_and_colors(&d))
		return (ft_error("Wrong inputs"));
	init_variables(&d);
	d.img.mlx = mlx_init();
	if (!(d.img.w = mlx_new_window(d.img.mlx, WIDTH, HEIGHT, TITLE)))
		return (ft_error("Window's creation failed"));
	(d.map_had_color == True) ? original_color(&d) : color_map(&d);
	d.help_display = 2;
	d.vertical_view = False;
	fdf(&d);
	return (0);
}
