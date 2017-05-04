/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_global_rotation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:53:04 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/25 16:48:40 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftmath.h"

float	**ft_matrix_global_rotation(float **m, t_vector a)
{
	float		**tmp;
	float		t;

	t = 1000000;
	tmp = ft_identity_matrix(0, 1);
	tmp[0][0] = (((F)(I)(cos(a.y) * t)) / t) * (((F)(I)(cos(a.z) * t)) / t);
	tmp[0][1] = (((F)(I)(cos(a.z) * t)) / t) * (((F)(I)(sin(a.x) * t)) / t)
	* (((F)(I)(sin(a.y) * t)) / t) - (((F)(I)(cos(a.x) * t)) / t)
	* (((F)(I)(sin(a.z) * t)) / t);
	tmp[0][2] = (((F)(I)(cos(a.x) * t)) / t) * (((F)(I)(cos(a.z) * t)) / t)
	* (((F)(I)(sin(a.y) * t)) / t) + (((F)(I)(sin(a.x) * t)) / t)
	* (((F)(I)(sin(a.z) * t)) / t);
	tmp[1][0] = (((F)(I)(cos(a.y) * t)) / t) * (((F)(I)(sin(a.z) * t)) / t);
	tmp[1][1] = (((F)(I)(cos(a.x) * t)) / t) * (((F)(I)(cos(a.z) * t)) / t)
	+ (((F)(I)(sin(a.x) * t)) / t) * (((F)(I)(sin(a.y) * t)) / t)
	* (((F)(I)(sin(a.z) * t)) / t);
	tmp[1][2] = (((F)(I)(-cos(a.z) * t)) / t) * (((F)(I)(sin(a.x) * t)) / t)
	+ (((F)(I)(cos(a.x) * t)) / t) * (((F)(I)(sin(a.y) * t)) / t)
	* (((F)(I)(sin(a.z) * t)) / t);
	tmp[2][0] = (((F)(I)(-sin(a.y) * t)) / t);
	tmp[2][1] = (((F)(I)(cos(a.y) * t)) / t) * (((F)(I)(sin(a.x) * t)) / t);
	tmp[2][2] = (((F)(I)(cos(a.x) * t)) / t) * (((F)(I)(cos(a.y) * t)) / t);
	m = ft_factor_matrix_free(m, tmp, 'B');
	return (m);
}
