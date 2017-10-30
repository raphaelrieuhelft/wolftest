/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 03:27:17 by vgallois          #+#    #+#             */
/*   Updated: 2017/10/30 03:28:13 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "wolf3d.h"

static void		draw_square(t_image *i, t_color c, t_vector v, int size)
{
	int	x;
	int	y;

	y = size * 2 + size * v.y;
	while (y < size * 2 + (size * (v.y + 1)))
	{
		x = size * 2 + size * v.x;
		while (x < size * 2 + (size * (v.x + 1)))
		{
			image_set_pixel(i, x, y, clerp(get_pixel(i, x, y), c, 0.5f).value);
			x++;
		}
		y++;
	}
}

void			draw_minimap(t_mlx *mlx)
{
	t_vector	v;
	int			size;

	size = WIN_WIDTH / 10 / mlx->map->w;
	v.x = 0;
	while (v.x < mlx->map->w)
	{
		v.y = 0;
		while (v.y < mlx->map->h)
		{
			if (get_tile(mlx->map, v.x, v.y))
				draw_square(mlx->image, (t_color)0xFFFFFF, v, size);
			v.y++;
		}
		v.x++;
	}
	v.x = mlx->player.x - 0.5f;
	v.y = mlx->player.y - 0.5f;
	draw_square(mlx->image, (t_color)0x00, v, size);
	v.x += mlx->player.d.x;
	v.y += mlx->player.d.y;
	draw_square(mlx->image, (t_color)0xFF0000, v, size);
}
