/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:40:42 by vgallois          #+#    #+#             */
/*   Updated: 2017/10/30 03:35:00 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
#define WOLF3D_H

# include <stdint.h>
# include <stdio.h>
# define MAP_WIDTH 25
# define MAP_HEIGHT 25
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define VIEW_DIST 25

typedef struct	s_rgba
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
}				t_rgba;

typedef union	s_color
{
	int			value;
	t_rgba		rgba;
}				t_color;

typedef struct	s_cast
{
	int			mx;
	int			my;
	float		sx;
	float		sy;
	float		dx;
	float		dy;
	int			stepx;
	int			stepy;
	float		wall;
}				t_cast;

typedef struct	s_vector
{
	float		x;
	float		y;
}				t_vector;

typedef struct	s_player
{
	float		x;
	float		y;
	t_vector	d;
	t_vector	p;
}				t_player;

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
	int			w;
	int			h;
}				t_image;

typedef struct	s_ray
{
	float		x;
	float		y;
	int			side;
	float		dist;
	float		height;
	int			tex_x;
	float		fx;
	float		fy;
}				t_ray;

typedef struct	s_map
{
	int			w;
	int			h;
	int			**value;
}				t_map;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_player	player;
	t_image		*image;
	t_map		*map;
}				t_mlx;

void		draw_minimap(t_mlx *mlx);
t_mlx		*init(char *title);
t_image		*del_image(t_mlx *mlx, t_image *img);
void		clear_image(t_image *img);
t_image 	*new_image(t_mlx *mlx, int w, int h);
void		image_set_pixel(t_image *image, int x, int y, int color);
t_color		get_pixel(t_image *i, int x, int y);
t_color		clerp(t_color c1, t_color c2, double p);
void		render(t_mlx *mlx);
int			hook_mouseup(int button, int x, int y, t_mlx *mlx);
int			hook_expose(t_mlx *mlx);
int			hook_keydown(int key, t_mlx *mlx);

int			get_tile(t_map *m, int x, int y);
void		cast(t_ray *r, t_map *m, t_player *p);
void		init_player(t_player *p);
void		rotate_player(t_player *p, float angle);
void		move_player(t_player *p, t_map *m, float distance);
t_map		*init_map(void);
#endif
