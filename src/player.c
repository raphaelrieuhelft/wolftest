/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 23:13:07 by vgallois          #+#    #+#             */
/*   Updated: 2017/10/30 02:34:25 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include <math.h>

void		init_player(t_player *p)
{
	p->x = 1.5f;
	p->y = 1.5f;
	p->d.x = 1.0f;
	p->d.y = 0.0f;
	p->p.x = 0.0f;
	p->p.y = 2.0f / 3.0f;
}

static void	rotate(t_vector *v, float angle)
{
	float x;
	float c;
	float s;

	x = v->x;
	c = cos(angle);
	s = sin(angle);
	v->x = v->x *c -v->y * s;
	v->y = x * s + v->y * c;
}

void		rotate_player(t_player *p, float angle)
{
	rotate(&p->d, angle);
	rotate(&p->p, angle);
}

void		move_player(t_player *p, t_map *m, float distance)
{
	if (!get_tile(m, p->x + distance * p->d.x, p->y))
		p->x += distance * p->d.x;
	if (!get_tile(m, p->x, distance + p->y * p->d.y))
		p->y += distance * p->d.y;
}
