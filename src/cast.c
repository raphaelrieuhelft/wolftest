/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 00:15:41 by vgallois          #+#    #+#             */
/*   Updated: 2017/10/31 03:53:19 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf3d.h"

static void	castfloor(t_ray *r, t_cast *t)
{
	r->fx = (float)t->mx + (r->side ? t->wall : 0) +
		(!r->side && r->x < 0 ? 1.0f : 0);
	r->fy = (float)t->my + (r->side ? 0 : t->wall) +
		(r->side && r->y < 0 ? 1.0f : 0);
}

static int	hittest(t_ray *r, t_cast *t, t_map *m)
{
	int		hit;
	int		blockdist;

	hit = 0;
	blockdist = 0;
	while (!hit && blockdist < 2 * VIEW_DIST)
	{
		if (t->sx < t->sy)
		{
			t->sx += t->dx;
			t->mx += t->stepx;
			r->side = 0;
		}
		else
		{
			t->sy += t->dy;
			t->my += t->stepy;
			r->side = 1;
		}
		if (t->mx < 0 || t->my < 0 || t->mx >= m->w || t->my >= m->h)
			break ;
		hit = get_tile(m, t->mx, t->my);
		blockdist++;
	}
	return (hit);
}

void		cast(t_ray *r, t_map *m, t_player *p, t_image *tex[])
{
	t_cast	t;
	int		hit;

	t.mx = (int)p->x;
	t.my = (int)p->y;
	t.dx = sqrt((r->y * r->y) / (r->x * r->x) + 1);
	t.dy = sqrt((r->x * r->x) / (r->y * r->y) + 1);
	t.stepx = (r->x < 0 ? -1 : 1);
	t.stepy = (r->y < 0 ? -1 : 1);
	t.sx = (r->x < 0 ? p->x - t.mx : t.mx - p->x + 1) * t.dx;
	t.sy = (r->y < 0 ? p->y - t.my : t.my - p->y + 1) * t.dy;
	r->height = 0;
	if ((hit = hittest(r, &t, m)))
	{
		r->dist = (r->side ? (t.my - p->y + (1 - t.stepy) / 2) / r->y :
				(t.mx - p->x + (1 - t.stepx) / 2) / r->x);
		r->height = (int)floor(WIN_HEIGHT / r->dist);
		r->texture = tex[hit];
		t.wall = (r->side ? p->x + r->dist * r->x : p->y + r->dist * r->y);
		t.wall -= floor(t.wall);
		r->tex_x = (int)(t.wall * r->texture->width);
		castfloor(r, &t);
	}
}
