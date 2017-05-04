/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 07:14:02 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/25 16:27:52 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** fcntl to use O_RDONLY, math for formulacs, nlx.h to trace pixel and window
** colors to use custom colors and keycode handle buttons and clicks' events.
*/

# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../libftmath/libftmath.h"
# include "colors.h"
# include "keycode_mac.h"

# define TITLE					"FDF"
# define PI						3.14159265359
# define HELP_COLOR				WHITE
# define HEIGHT					1400
# define WIDTH					2000
# define FRAME_WIDTH					200
# define MAX_UNIT_SIZE			20

/*
** macros used for still inputs
*/

# define KEYPRESS				2
# define KEYRELEASE				3
# define KEYPRESSMASK			(1L << 0)
# define KEYRELEASEMASK			(1L << 1)

/*
** more awesome colors
*/

# define PINK					0xcc00cc
# define BLACK					0x000000
# define MARINE_BLUE			0x000099
# define CRIMSON_RED			0x990033
# define NICE_BLUE				0x6666ff
# define DARK_TEAL				0x33cccc
# define GREY					0xd3d3d3
# define BROWN					0x996633
# define TRANSPARENT			0x77000000

/*
** a is alpha(transparency) r = red g = green b = blue
** argb stores inside .x the color used to draw the pixel
** and in y the required incrementation
*/

typedef struct	s_argb
{
	float		a;
	float		r;
	float		g;
	float		b;
}				t_argb;

typedef struct	s_argb2
{
	t_argb		x;
	t_argb		y;
}				t_argb2;

typedef struct	s_hexcolor
{
	long		x;
	long		y;
}				t_hexcolor;

typedef struct	s_fxy
{
	float		x;
	float		y;
}				t_fxy;

/*
** points are stored using this structure in convert_2_to_3d
*/

typedef struct	s_index
{
	int			x;
	int			y;
}				t_index;

/*
** first project where I use mlx. w is the window or frame.
*/

typedef struct	s_image
{
	void		*mlx;
	void		*w;
	int			*image;
	char		*data_address;
	int			bpp;
	int			line_size;
	int			endian;
}				t_image;

/*
** *s is map parsed as a string and *c a save from each point's color.
** vertical_view if the initial view of the map.
** full description of variables below is written in init_variables.
*/

typedef struct	s_3d
{
	t_image		img;
	char		*s;
	t_index		max;
	float		depth;
	t_bool		vertical_view;
	t_vector	angle;
	t_vector	offs;
	t_vector	scaling;
	t_vector	center;
	t_index		dimension;
	t_vector	**m;
	t_vector	**mm;
	long		**c;
	long		**cm;
	t_hexcolor	colors;
	float		**matrix;
	float		**matrix_tmp;
	short		z_max;
	short		z_min;
	short		season;
	t_argb		l;
	short		help_display;
	t_bool		map_had_color;
	int			shade;
}				t_3d;

/*
** parsing.c ~ parsing functions
*/

int				read_map(t_3d *d, char *s);
short			parse_map(char *s);
t_bool			parse_digit(char *s, unsigned *i);
t_bool			parse_color(char *s, unsigned *i);
int				malloc_map(t_3d *d);
int				get_depth_and_colors(t_3d *d);
long			get_colors(t_3d *d);

/*
** fdf.c ~ tracing lines algorytmes
*/

int				fdf(t_3d *d);
void			init_variables(t_3d *d);
void			apply_matrix(t_3d *d);
void			norm_rotation(t_3d *d, char axis, char direction);
void			recalculate_center(t_3d *d);

/*
** ft_draw.c ~ mlx related functions
*/

void			ft_put_pixel_in_img(t_3d *d, t_vector a, t_argb color);
void			ft_draw(t_3d *d);
void			ft_lines_draw(t_3d *d, t_vector a, t_vector b, t_hexcolor c);
void			ft_create_image(t_image *img);

/*
** color.c ~ gradient colors functions
*/

void			color_map(t_3d *d);
void			original_color(t_3d *d);
t_argb2			gradient(unsigned a, unsigned b, int pixel);
t_argb			ft_hex2argb(long hex);
long			ft_argb2hex(t_argb rgb);
unsigned		custom_color(t_3d *d, t_argb color, int shade);

/*
** user hook is the function used to dectect inputs from user.
** settings is the menu
*/

int				translation_hoo(int keycode, t_3d *d);
int				scaling_hook(int keycode, t_3d *d);
int				color_hook(int keycode, t_3d *d);
int				user_hook(int keycode, t_3d *d);
void			ft_settings(t_3d *d);
void			free_all(t_3d *d);

#endif
