/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:21:18 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/25 16:09:18 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

/*
** creates a new image
*/

void		ft_create_image(t_image *img)
{
	img->image ? mlx_destroy_image(img->mlx, img->image) : 0;
	img->w ? mlx_clear_window(img->mlx, img->w) : 0;
	img->image = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->data_address = mlx_get_data_addr(img->image, &(img->bpp),
			&(img->line_size), &(img->endian));
}

/*
** draw each lines starting from (y, x) to (y + 1, x) and (y, x + 1)
*/

void		ft_draw(t_3d *d)
{
	t_index		i;
	t_hexcolor	color;

	i.y = 0;
	while (i.y < d->max.y)
	{
		i.x = -1;
		while (++i.x < d->max.x)
		{
			color.x = d->cm[i.y][i.x];
			if (i.x < d->max.x - 1)
			{
				color.y = d->cm[i.y][i.x + 1];
				ft_lines_draw(d, d->mm[i.y][i.x], d->mm[i.y][i.x + 1], color);
			}
			if (i.y < d->max.y - 1)
			{
				color.y = d->cm[i.y + 1][i.x];
				ft_lines_draw(d, d->mm[i.y][i.x], d->mm[i.y + 1][i.x], color);
			}
		}
		++i.y;
	}
	ft_lines_draw(d, d->mm[i.y - 1][i.x - 1], d->mm[i.y - 1][i.x - 1], color);
}

/*
** draw lines between points using Gressenham algorytm
** the condition evalues that the starting pixel is inside the frame
*/

void		ft_lines_draw(t_3d *d, t_vector a, t_vector b, t_hexcolor c)
{
	t_fxy		dif;
	t_fxy		i;
	t_argb2		grad;
	int			pixel;
	double		tmp;

	dif.x = fabs(b.x - a.x);
	dif.y = fabs(b.y - a.y);
	tmp = (dif.x > dif.y) ? dif.x : dif.y;
	pixel = (!round(tmp)) ? 1 : round(tmp);
	i.x = dif.x / tmp * (a.x < b.x ? 1 : -1);
	i.y = dif.y / tmp * (a.y < b.y ? 1 : -1);
	grad = gradient(c.x, c.y, pixel);
	while (pixel--)
	{
		if ((a.x > WIDTH && a.x < 0) && (a.y > HEIGHT && a.y < 0))
			pixel = 0;
		ft_put_pixel_in_img(d, a, grad.x);
		a.x += i.x;
		a.y += i.y;
		grad.x.r += grad.y.r;
		grad.x.g += grad.y.g;
		grad.x.b += grad.y.b;
		grad.x.a += grad.y.a;
	}
}

/*
** Puts exactly one pixel in the image
** As d->cm[y][x] is the color expressed as integer, we take the address
** of d->data_address and then cast it as (int *) before dereferencing to
** save color value inside.
*/

void		ft_put_pixel_in_img(t_3d *d, t_vector a, t_argb c)
{
	int			x;
	int			y;
	long		color;

	x = round(a.x) + d->offs.x;
	y = round(a.y) + d->offs.y;
	color = custom_color(d, c, d->shade);
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
		*(int *)&d->img.data_address[(x * d->img.bpp / 8) +
			(y * d->img.line_size)] = color;
}

/*
** the d->l is used for night/day and transparency effects.
** a shade binary filter is applied by shifting right each color by 1 bit.
*/

unsigned	custom_color(t_3d *d, t_argb color, int shade)
{
	color.a = ft_clamp((int)round(color.a + d->l.a), 0, 0xff);
	color.r = ft_clamp((int)round(color.r + d->l.r), 0, 0xff);
	color.g = ft_clamp((int)round(color.g + d->l.g), 0, 0xff);
	color.b = ft_clamp((int)round(color.b + d->l.b), 0, 0xff);
	color.a = (int)color.a >> shade;
	color.r = (int)color.r >> shade;
	color.g = (int)color.g >> shade;
	color.b = (int)color.b >> shade;
	return (ft_argb2hex(color));
}
