/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 22:47:24 by vgallois          #+#    #+#             */
/*   Updated: 2017/10/31 03:46:42 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "keys.h"
#include <stdlib.h>
#include <math.h>

int		hook_keydown(int key, t_mlx *mlx)
{
	if (!mlx)
		return (0);
	if (key == K_ESC)
	{
		system("killall afplay &");
		exit(EXIT_SUCCESS);
	}
	if (key == K_LEFT)
		rotate_player(&mlx->player, -6.0f / 180.0f * M_PI);
	if (key == K_RIGHT)
		rotate_player(&mlx->player, 6.0 / 180.0f * M_PI);
	if (key == K_UP)
		move_player(&mlx->player, mlx->map, 0.2f);
	if (key == K_DOWN)
		move_player(&mlx->player, mlx->map, -0.2f);
	render(mlx);
	return (0);
}
