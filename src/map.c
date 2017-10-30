/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:59:18 by vgallois          #+#    #+#             */
/*   Updated: 2017/10/30 02:42:10 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"

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
		{
			if (i == 0 || j == 0 || i == MAP_HEIGHT - 1
				|| j == MAP_WIDTH - 1)
				m->value[i][j] = 1;
			else
				m->value[i][j] = 0;
			j++;
		}
		i++;
	}
	m->value[5][0] = 0;
	return (m);
}
