/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_converter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:07:01 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/23 14:31:48 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

t_argb	ft_hex2argb(long hex)
{
	t_argb	argb;

	argb.a = (hex >> 24) & 0xFF;
	argb.r = (hex >> 16) & 0xFF;
	argb.g = (hex >> 8) & 0xFF;
	argb.b = hex & 0xFF;
	return (argb);
}

long	ft_argb2hex(t_argb argb)
{
	return (((int)argb.a << 24) + ((int)argb.r << 16)
	+ ((int)argb.g << 8) + argb.b);
}

/*
** stores the needed gradiant color increase in c.y and starting color in c.x
** on bitwise operators: a & 0xFF is equivalent to a % 256  as 0xFF = 255.
** >> 8 is used to divide color by 2^8 = 256, removing blue, and then red.
** the more c.x.a is close to 0xff and the more it will be transparent.
*/

t_argb2	gradient(unsigned a, unsigned b, int pixel)
{
	t_argb2		c;

	c.x.b = a & 0xFF;
	c.y.b = b & 0xFF;
	c.y.b = (c.y.b - c.x.b) / pixel;
	c.x.g = a >> 8 & 0xFF;
	c.y.g = b >> 8 & 0xFF;
	c.y.g = (c.y.g - c.x.g) / pixel;
	c.x.r = a >> 16 & 0xFF;
	c.y.r = b >> 16 & 0xFF;
	c.y.r = (c.y.r - c.x.r) / pixel;
	c.x.a = a >> 24 & 0xFF;
	c.y.a = b >> 24 & 0xFF;
	c.y.a = (c.y.a - c.x.a) / pixel;
	return (c);
}
