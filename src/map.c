/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:59:18 by vgallois          #+#    #+#             */
/*   Updated: 2017/10/31 04:19:18 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include <math.h>

int		get_tile(t_map *m, int x, int y)
{
	if (x < 0 || y < 0 || x > m->w - 1 || y > m->h - 1)
		return (0);
	return (m->value[y][x]);
}

t_map	*new_map(void)
{
	t_map	*m;
	int		i;

	if ((m = (t_map *)ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	if ((m->value = (int **)ft_memalloc(sizeof(int *) * MAP_WIDTH)) == NULL)
	{
		ft_memdel((void **)&m);
		return (NULL);
	}
	i = 0;
	while (i < MAP_HEIGHT)
	{
		if (!(m->value[i] = (int *)ft_memalloc(sizeof(int) * MAP_HEIGHT)))
		{
			while (i > 0)
				ft_memdel((void **)(m->value + --i));
			ft_memdel((void **)&m);
			return (NULL);
		}
		i++;
	}
	return (m);
}

void	wall(int p1, int p2, t_map *m)
{
	int x;
	int x1;
	int x2;
	int y1;
	int y2;

	x1 = p1 / 100;
	y1 = p1 % 100;
	x2 = p2 / 100;
	y2 = p2 % 100;
	y2 = (y2 > MAP_HEIGHT - 2 ? MAP_HEIGHT - 2 : y2);
	x2 = (x2 > MAP_WIDTH - 2 ? MAP_WIDTH - 2 : x2);
	while (y1 <= y2)
	{
		x = x1;
		while (x <= x2)
			m->value[y1][x++] = 0;
		y1++;
	}
}

t_map	*init_map(void)
{
	t_map	*m;
	int		i;
	int		j;

	m = new_map();
	m->w = MAP_WIDTH;
	m->h = MAP_HEIGHT;
	i = 0;
	while (i < MAP_HEIGHT)
	{
		j = 0;
		while (j < MAP_WIDTH)
			m->value[i][j++] = 1;
		i++;
	}
	wall(101, 1001, m);
	wall(501, 505, m);
	wall(301, 308, m);
	wall(103, 303, m);
	wall(103, 115, m);
	wall(507, 1501, m);
	wall(110, 510, m);
	wall(507, 1515, m);
	return (m);
}
