/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:34:04 by vgallois          #+#    #+#             */
/*   Updated: 2017/10/31 03:57:06 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

static int	hook_close(t_mlx *mlx)
{
	(void)mlx;
	system("killall afplay&");
	exit(EXIT_SUCCESS);
	return (0);
}

int			die(char *c)
{
	ft_putendl(c);
	exit(EXIT_FAILURE);
	return (1);
}

int			main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 1)
		return (die(argv[0]));
	if (!(mlx = init("title")))
		die("init error");
	if (load_textures(mlx))
		return (die("textures error"));
	mlx->map = init_map();
	init_player(&mlx->player);
	system("afplay music.mp3 &");
	render(mlx);
	mlx_hook(mlx->window, 2, 1L << 0, hook_keydown, mlx);
	mlx_hook(mlx->window, 17, 1L << 0, hook_close, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
