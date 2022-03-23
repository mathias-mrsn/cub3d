/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:02:06 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/23 13:56:14 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define DELAY_TIME 0.04

void
	update_gun_sprite(t_cub *s)
{
	const clock_t	now = clock();

	if (s->moves->fire || s->gun->gun_state)
	{
		if (!s->gun->gun_state)
		{
			s->gun->gun_state = 1;
			s->gun->time = clock();
			s->gun->can_kill = true;
			system(CMD_PLAY_SOUND" "SOUND_GUN_PATH" 2>/dev/null&");
		}
		else
		{
			s->gun->can_kill = false;
			if (((double)(now - s->gun->time) / CLOCKS_PER_SEC) < DELAY_TIME)
				return ;
			s->gun->time = now;
			s->gun->gun_state += 1;
			if (s->gun->gun_state == NBR_GUN_SPRITE)
				s->gun->gun_state = 0;
		}
	}
}

void
	put_gun_cursor(t_cub *s)
{
	int	x_cent;
	int	y_cent;

	x_cent = s->win_x / 2 - 2;
	while (x_cent < ((s->win_x / 2) + 2))
	{
		y_cent = s->win_y / 2 - 2;
		while (y_cent < ((s->win_y / 2) + 2))
		{
			__put_pixel_on_img(&s->img, x_cent, y_cent, 0xFFFFFF);
			y_cent++;
		}
		x_cent++;
	}
}

void
	put_gun_on_img(t_cub *s, double i, double j)
{
	const t_img	txtr = s->gun->gun_txtr[s->gun->gun_state];
	uint32_t	*color;
	int			x;
	int			y;

	x = (s->win_x / 2) - (fmin(s->win_x, s->win_y) / 2);
	y = (s->win_y - fmin(s->win_x, s->win_y));
	i = 0.0;
	while (i < txtr.x)
	{
		j = 0.0;
		while (j < txtr.y)
		{
			color = ((uint32_t *)(txtr.addr
						+ ((((int)i * txtr.bpp / 8) * txtr.y))
						+ (int)j * txtr.bpp / 8));
			if (*color != (uint32_t)9961608)
				__put_pixel_on_img(&s->img, x, y, *color);
			x++;
			j += txtr.y / fmin(s->win_x, s->win_y);
		}
		y++;
		x = (s->win_x / 2) - (fmin(s->win_x, s->win_y) / 2);
		i += txtr.x / fmin(s->win_x, s->win_y);
	}
}
