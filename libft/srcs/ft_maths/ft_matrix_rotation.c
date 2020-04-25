/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:50:17 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/20 23:02:05 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftmath.h"

float	**ft_matrix_rotation(float x, char axis)
{
	float**m;

	m = ft_identity_matrix(0, 1);
	if (axis == 'x')
	{
		m[1][1] = cos(x);
		m[1][2] = -sin(x);
		m[2][2] = cos(x);
		m[2][1] = sin(x);
	}
	else if (axis == 'y')
	{
		m[0][0] = cos(x);
		m[0][2] = sin(x);
		m[2][0] = -sin(x);
		m[2][2] = cos(x);
	}
	else if (axis == 'z')
	{
		m[0][0] = cos(x);
		m[0][1] = -sin(x);
		m[1][0] = sin(x);
		m[1][1] = cos(x);
	}
	return (m);
}
