/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmath.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 22:59:57 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/25 16:43:07 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMATH_H
# define LIBFTMATH_H

# include <math.h>
# include <stdlib.h>

# define I int
# define F float

typedef struct	s_i
{
	int		x;
	int		y;
	int		z;
}				t_i;

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vector;

/*
** Miscellaneous
*/

int				ft_clamp(int n, int min, int max);
void			ft_putnbr_base(int n, int b);
long			ft_htoi(char *s);
void			ft_puthex(int n);
int				ft_isdigit(int c);

/*
** Matrix
*/

float			**ft_identity_matrix(int fill, int fill_diagonal);
float			**ft_matrix_rotation(float x, char axis);
float			**ft_matrix_global_rotation(float **m, t_vector angle);
float			**ft_matrix_scaling(float **m, t_vector scaling);
float			**ft_matrix_z_scaling(float **matrix, float coefficient);
float			**ft_sum_matrix(float **a, float **b);
float			**ft_factor_matrix_free(float **a, float **b, char free);
t_vector		ft_matrix_to_vector(float **m, t_vector v, t_vector center);
void			ft_free_matrix(float **m);
float			**ft_copy_matrix(float **m);

#endif
