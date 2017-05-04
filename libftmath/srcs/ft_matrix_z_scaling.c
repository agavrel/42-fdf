/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_z_scaling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:12:25 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/22 02:54:28 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftmath.h"

float	**ft_matrix_z_scaling(float **matrix, float coefficient)
{
	matrix[0][2] *= coefficient;
	matrix[1][2] *= coefficient;
	return (matrix);
}
