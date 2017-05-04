/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:21:49 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/25 16:32:58 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void		ft_help_display(t_image *img, unsigned c)
{
	short		x;

	x = 20;
	mlx_string_put(img->mlx, img->w, x, 15, c, "Push 'H' to close help and");
	mlx_string_put(img->mlx, img->w, x + 265, 15, RED, " SPEED UP");
	mlx_string_put(img->mlx, img->w, x + 355, 15, c, " the program");
	mlx_string_put(img->mlx, img->w, x, 40, c,
			"West, East, North, South : [<-] [->] [^] [v]");
	mlx_string_put(img->mlx, img->w, x, 65, c, "Zoom In / Out : [+] / [-]");
	mlx_string_put(img->mlx, img->w, x, 95, c,
			"Change Color : NUMPAD [0]Spring [1]Summer... [4] Original");
	mlx_string_put(img->mlx, img->w, x, 125, c,
			"Increase / Decrease Altitude : [Q] / [E]");
	mlx_string_put(img->mlx, img->w, x, 155, c,
			"Rotate around Z, Y, X, all axis : [1,2],[3,4],[5,6],[7,8]");
	mlx_string_put(img->mlx, img->w, x, 180, c,
			"Increase / Decrease brightness : [9] / [0]");
	mlx_string_put(img->mlx, img->w, x, 210, c,
			"Increase / Decrease transparency : [,] / [.]");
	mlx_string_put(img->mlx, img->w, x, 240, c,
			"SPACE : Reset map to initial position");
	mlx_string_put(img->mlx, img->w, x, 275, c,
			"Exit : [ESCAPE]");
}

void			ft_settings(t_3d *d)
{
	t_index		i;
	t_index		max;
	int			border;

	max.y = (d->help_display >> 1) ? 50 : 305;
	max.x = (d->help_display >> 1) ? 360 : 700;
	i.y = -1;
	border = 4;
	while (++i.y < max.y)
	{
		i.x = -1;
		while (++i.x < max.x)
		{
			if (i.x > border && i.x < max.x - border && i.y > border && i.y
					< max.y - border)
				mlx_pixel_put(d->img.mlx, d->img.w, i.x, i.y, TRANSPARENT);
			else
				mlx_pixel_put(d->img.mlx, d->img.w, i.x, i.y, BLUE);
		}
	}
	if (d->help_display != 2)
		ft_help_display(&(d->img), HELP_COLOR);
	else
		mlx_string_put(d->img.mlx, d->img.w, 15, 10, HELP_COLOR,
			"Display Menu : Press [H] Button");
}
