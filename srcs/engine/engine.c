/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:19:40 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/22 10:43:10 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	update_sprite_to_print(t_cub *s)
{
	clock_t	now;
	uint64_t	diff;

	if (s->time == 0)
		s->time = clock() / SPRITE_INTERVAL;
	now = clock() / SPRITE_INTERVAL;
	diff = now - s->time;
	if (diff >= 1)
	{
		s->sprite_to_print += 1;
		if (s->sprite_to_print >= s->parser->nbr_sprite)
			s->sprite_to_print = 0;
	}
	s->time = now;
}

int
	hit_box_sprite(t_cub *s, t_raycasting *rayc, int col)
{
	t_sprite *tmp;
	const t_img		txtr = s->textures->sprite[s->sprite_to_print];
	


	tmp = (t_sprite *)rayc->head;
	while (tmp)
	{
		if (tmp->error)
		{
			tmp = tmp->next;
			continue;
		}
		double scale = (s->win_y / tmp->distance_fc);
		double		idx = 0;

		double draw_start = (-scale / 2) + (s->win_y / 2);
		double draw_end = (scale / 2) + (s->win_y / 2);

		if (scale > s->win_y)
		{
			draw_start = 0.0;
			draw_end = s->win_y;
			idx = (txtr.y * (1 - s->win_y / scale)) / 2;
		}
		while (draw_start < draw_end && draw_start < s->win_y)
		{
			uint32_t	*color = ((uint32_t *)(txtr.addr
					+ ((((int)idx * txtr.bpp / 8) * txtr.y))
					+ (int)(tmp->texture_x * txtr.x)
					*txtr.bpp / 8));
			if (*color != 0)
				return (1);
			draw_start++;
			idx += (double)txtr.y / (double)(scale);
		}
		tmp = tmp->next;
	}
	return (0);
}

int
	engine(t_cub *s)
{
	int				col;
	t_raycasting	ray;

	col = 0;
	// __print_memory();
	mouse_move(s);
	moves(s);
	update_sprite_to_print(s);
	update_doors(s);
	update_gun_sprite(s);
	while (col < s->win_x)
	{
		__memset(&ray, 0, sizeof(t_raycasting));
		init_raycasting(s, &ray, col);
		cast_ray(s, &ray);
		if (col == s->win_x / 2 && hit_box_sprite(s, &ray, col))
			kill_sprite(s, &ray);
		put_ray_on_img(s, &ray, col);
		put_sprite_on_img(s, &ray, col);
		col++;
	}
	put_gun_cursor(s);
	put_gun_on_img(s);
	map2d(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img.ptr, 0, 0);
	__clean(SPRITE_STACK);
	return (__SUCCESS);
}
