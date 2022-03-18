/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:19:40 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/18 09:53:23 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	update_sprite_to_print(t_cub *s)
{
	clock_t	now;
	uint64_t	diff;

	if (s->time == 0)
		s->time = clock() / 50000;
	now = clock() / 50000;
	diff = now - s->time;
	if (diff >= 1)
	{
		s->sprite_to_print += 1;
		if (s->sprite_to_print >= s->parser->nbr_sprite)
			s->sprite_to_print = 0;
	}
	s->time = now;
	printf("%llu\n", diff);
}

int
	engine(t_cub *s)
{
	int				col;
	t_raycasting	ray;

	col = 0;
	mouse_move(s);
	moves(s);
	update_sprite_to_print(s);
	while (col < s->win_x)
	{
		__memset(&ray, 0, sizeof(t_raycasting));
		init_raycasting(s, &ray, col);
		cast_ray(s, &ray);
		put_ray_on_img(s, &ray, col);
		put_sprite_on_img(s, &ray, col);
		col++;
	}
	map2d(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img.ptr, 0, 0);
	return (__SUCCESS);
}
