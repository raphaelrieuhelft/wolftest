/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:34:04 by vgallois          #+#    #+#             */
/*   Updated: 2017/10/30 02:34:34 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include "mlx.h"

int		die(char *c)
{
	ft_putendl(c);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 1)
		return (die(argv[0]));
	if (!(mlx = init("title")))
		die("init error");
	mlx->map = init_map();
	init_player(&mlx->player);
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
