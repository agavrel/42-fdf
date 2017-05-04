/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_to_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:48:15 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/25 16:39:31 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftmath.h"

t_vector	ft_matrix_to_vector(float **m, t_vector v, t_vector c)
{
	t_vector	n;

	v.x -= c.x;
	v.y -= c.y;
	v.z -= c.z;
	n.x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + m[0][3] * v.w + c.x;
	n.y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + m[1][3] * v.w + c.y;
	n.z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + m[2][3] * v.w + c.z;
	n.w = v.x * m[3][0] + v.y * m[3][1] + v.z * m[3][2] + m[3][3] * v.w;
	return (n);
}
