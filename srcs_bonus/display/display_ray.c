/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:24:23 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/30 13:38:42 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double
	__find_x_value__(t_raycasting *rayc)
{
	double	res;

	if (rayc->wall_type == NORTH_SIDE || rayc->wall_type == SOUTH_SIDE)
		res = (rayc->hit_x);
	else
		res = (rayc->hit_y);
	if (rayc->hit_door && (rayc->wall_type == NORTH_SIDE
			|| rayc->wall_type == SOUTH_SIDE))
		res -= rayc->door->opening_x;
	else if (rayc->hit_door)
		res -= rayc->door->opening_x;
	return (res);
}

static void
	put_texture(t_cub *s, t_raycasting *rayc, double scale, int col)
{
	const t_img		txtr = s->textures->walls[__trnu32(rayc->hit_door,
			DOOR, rayc->wall_type)];
	const double	ratio_y = (double)txtr.y / (double)(scale);
	double			draw_start;
	double			draw_end;
	double			idx;

	idx = 0.0;
	draw_start = (-scale / 2) + (s->win_y / 2);
	draw_end = (scale / 2) + (s->win_y / 2);
	if (scale > s->win_y)
	{
		draw_start = 0.0;
		draw_end = s->win_y;
		idx = (txtr.y * (1 - s->win_y / scale)) / 2;
	}
	while (draw_start < draw_end && draw_start < s->win_y && idx < txtr.y)
	{
		__put_pixel_on_img(&s->img, col, draw_start, *((uint32_t *)(txtr.addr
					+ ((((int)idx * txtr.bpp / 8) * txtr.x))
					+ (int)(get_decimal(__find_x_value__(rayc)) * txtr.x)
					*txtr.bpp / 8)));
		draw_start++;
		idx += ratio_y;
	}
}

void
	put_ray_on_img(t_cub *s, t_raycasting *rayc, int col)
{
	double	scale;
	int		idx;

	idx = 0;
	scale = s->win_y / (rayc->distance * cos(rayc->dirx - s->player->angle));
	while (idx < (-scale / 2) + (s->win_y / 2))
	{
		__put_pixel_on_img(&s->img, col, idx, (int)s->textures->ceil);
		idx++;
	}
	put_texture(s, rayc, scale, col);
	idx = (scale / 2) + (s->win_y / 2);
	while (idx < s->win_y)
	{
		__put_pixel_on_img(&s->img, col, idx, (int)s->textures->floor);
		idx++;
	}
}

void
	put_sprite(t_cub *s, t_sprite *sprite, int col, t_img txtr)
{
	const double	scale = (s->win_y / sprite->distance_fc);
	uint32_t		*color;
	double			draw_start;
	double			draw_end;
	double			idx;

	idx = 0.0;
	draw_start = (-scale / 2) + (s->win_y / 2) - 1;
	draw_end = (scale / 2) + (s->win_y / 2);
	if ((s->win_y / sprite->distance_fc) > s->win_y)
	{
		draw_start = -1.0;
		draw_end = s->win_y;
		idx = (txtr.y * (1 - s->win_y / scale)) / 2;
	}
	while (++draw_start < draw_end && draw_start < s->win_y && idx < txtr.y)
	{
		color = ((uint32_t *)(txtr.addr
					+ ((((int)idx * txtr.bpp / 8) * (txtr.x)))
					+ (int)(sprite->texture_x * txtr.x) * \
					txtr.bpp / 8));
		if (*color != 0U)
			__put_pixel_on_img(&s->img, col, draw_start, (*color));
		idx += (double)txtr.y / (double)scale;
	}
}

void
	put_sprite_on_img(t_cub *s, t_raycasting *rayc, int col)
{
	t_sprite	*tmp;
	const t_img	txtr = s->textures->sprite[s->sprite_to_print];

	tmp = (t_sprite *)rayc->head;
	while (tmp)
	{
		if (!tmp->error)
		{
			put_sprite(s, tmp, col, txtr);
		}
		tmp = tmp->next;
	}
}
