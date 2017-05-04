/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:23:05 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/25 16:59:31 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

/*
** Variable initialization
** gamma ~ g, scaling ~ zoom, translation on x axis ~ offs.x
** z amplitude ~ depth, image and matrix set to NULL and identity_matrix
** map default colors ~ season {0, 3}, rotation around x axis ~ angle.x.
*/

int		color_hook(int k, t_3d *d)
{
	if (k == KEY_PAD_0)
		d->season = 0;
	else if (k == KEY_PAD_1)
		d->season = 1;
	else if (k == KEY_PAD_2)
		d->season = 2;
	else if (k == KEY_PAD_3 || k == KEY_PAD_4)
		d->season = (k == KEY_PAD_3) ? 3 : 4;
	d->season < 4 ? color_map(d) : original_color(d);
	if (k == 25)
	{
		d->l.r = ft_clamp((int)d->l.r + 4, -0xff, 0x33);
		d->l.g = ft_clamp((int)d->l.g + 4, -0xff, 0x33);
		d->l.b = ft_clamp((int)d->l.b + 4, -0xff, 0x33);
	}
	else if (k == 29)
	{
		d->l.r = ft_clamp((int)d->l.r - 4, -0xff, 0x33);
		d->l.g = ft_clamp((int)d->l.g - 4, -0xff, 0x33);
		d->l.b = ft_clamp((int)d->l.b - 4, -0xff, 0x33);
	}
	else if (k == 47 || k == 43)
		d->l.a = (k == 47) ? ft_clamp((int)d->l.a + 4, 0, 0xff) :
		ft_clamp((int)d->l.a - 4, 0, 0xff);
	return (1);
}

int		translation_hook(int k, t_3d *d)
{
	if (k >= 123 && k <= 126)
	{
		if (k == 123 || k == 124)
			d->offs.x += (k == 123) ? 20 : -20;
		else if (k == 125 || k == 126)
			d->offs.y += (k == 125) ? -20 : 20;
	}
	return (1);
}

int		rotation_hook(int k, t_3d *d)
{
	if (k == 18 || k == 19)
		(k == 19) ? norm_rotation(d, 'z', '+') : norm_rotation(d, 'z', '-');
	else if (k == 20 || k == 21)
		(k == 21) ? norm_rotation(d, 'y', '+') : norm_rotation(d, 'y', '-');
	else if (k == 23 || k == 22)
		(k == 22) ? norm_rotation(d, 'x', '+') : norm_rotation(d, 'x', '-');
	else if (k == 26 || k == 28)
		k == 26 ? norm_rotation(d, 'a', '+') : norm_rotation(d, 'a', '-');
	return (1);
}

int		scaling_hook(int k, t_3d *d)
{
	if (k == 69)
	{
		d->scaling.x *= 1.25;
		d->scaling.y *= 1.25;
		d->scaling.z *= 1.25;
		d->scaling.w *= 1.25;
	}
	else if (k == 78 && d->scaling.x > 0.05)
	{
		d->scaling.x *= 0.9;
		d->scaling.y *= 0.9;
		d->scaling.z *= 0.9;
		d->scaling.w *= 0.9;
	}
	else if (k == 12 || k == 14)
	{
		if (k == 14 && d->depth < 12)
			d->depth *= 1.10;
		else if (d->depth > 0.05)
			d->depth *= 0.9;
	}
	return (1);
}

/*
** variable k stands for keycode; button pushed by user
** buttons' effect full description is displayed if 'H' button is pushed
*/

int		user_hook(int k, t_3d *d)
{
	if (k == 53)
		mlx_destroy_window(d->img.mlx, d->img.w);
	if (k == 53)
		exit(0);
	else if (k == 49 || k == KEY_P)
	{
		if (k == KEY_P)
			d->vertical_view = (d->vertical_view == False) ? True : False;
		mlx_clear_window(d->img.mlx, d->img.w);
		init_variables(d);
		fdf(d);
	}
	else
	{
		if (k == KEY_H)
			d->help_display = (d->help_display == 1) ? 0 : 1;
		rotation_hook(k, d);
		color_hook(k, d);
		translation_hook(k, d);
		scaling_hook(k, d);
		mlx_clear_window(d->img.mlx, d->img.w);
		fdf(d);
	}
	return (1);
}
