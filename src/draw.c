/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:23:36 by vgallois          #+#    #+#             */
/*   Updated: 2017/10/30 03:33:37 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include "mlx.h"

static t_color	c(int v)
{
	t_color c;

	c.value = v;
	return (c);
}
static void		draw_floor(t_mlx *mlx, t_ray *r, int x, int y)
{
	c(r->side);
	while (y < WIN_HEIGHT)
	{
		image_set_pixel(mlx->image, x, y, 0xD4D4D4);
		image_set_pixel(mlx->image, x, WIN_HEIGHT - y, 0x3FE0F2);
		y++;
	}
}

static void		draw_column(t_mlx *mlx, t_ray *r, int x)
{
	int		y;
	int		start;
	int		end;

	start = (WIN_HEIGHT - r->height) / 2;
	end = start + r->height;
	if (start < 0)
		start = 0;
	if (end > WIN_HEIGHT - 1)
		end = WIN_HEIGHT - 1;
	y = start;
	while (y < end)
	{
		image_set_pixel(mlx->image, x, y++, 0xB42626);
	}
	draw_floor(mlx, r, x, y);
}

void			render(t_mlx *mlx)
{
	int		x;
	t_ray	ray;
	float	camera;

	clear_image(mlx->image);
	x = 0;
	while (x < WIN_WIDTH)
	{
		camera = 2.0f * x / WIN_WIDTH - 1.0f;
		ray.x = mlx->player.d.x + mlx->player.p.x * camera;
		ray.y = mlx->player.d.y + mlx->player.p.y * camera;
		cast(&ray, mlx->map, &mlx->player);
		draw_column(mlx, &ray, x);
		x++;
	}
	draw_minimap(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
