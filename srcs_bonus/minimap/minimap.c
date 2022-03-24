/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:53:28 by malouvar          #+#    #+#             */
/*   Updated: 2022/03/24 10:26:21 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	draw_elem(t_cub *s, int pxl_x, int pxl_y)
{
	double	x;
	double	y;

	x = s->player->p_x - (double)(DIST_PER_PIXEL * (CENTER_X - pxl_x));
	y = s->player->p_y - (double)(DIST_PER_PIXEL * (CENTER_Y - pxl_y));
	if (x > 0.0 && y > 0.0 && x < s->map_width
		&& y < s->map_height && s->map[(int)y][(int)x] == '1')
		__put_pixel_on_img(&s->img, (pxl_x + PADDING_X + BORDER),
			(pxl_y + PADDING_Y + BORDER), WALL_COLOR);
	else if (x > 0.0 && y > 0.0 && x < s->map_width
		&& y < s->map_height && s->map[(int)y][(int)x] == 'D')
		__put_pixel_on_img(&s->img, (pxl_x + PADDING_X + BORDER),
			(pxl_y + PADDING_Y + BORDER), DOOR_COLOR);
	else if (x > 0.0 && y > 0.0 && x < s->map_width
		&& y < s->map_height && s->map[(int)y][(int)x] == '2')
		__put_pixel_on_img(&s->img, (pxl_x + PADDING_X + BORDER),
			(pxl_y + PADDING_Y + BORDER), SPRITE_COLOR);
	else if (x > 0.0 && y > 0.0 && x < s->map_width
		&& y < s->map_height && s->map[(int)y][(int)x] == '0')
		__put_pixel_on_img(&s->img, (pxl_x + PADDING_X + BORDER),
			(pxl_y + PADDING_Y + BORDER), s->textures->floor);
	else
		__put_pixel_on_img(&s->img, (pxl_x + PADDING_X + BORDER),
			(pxl_y + PADDING_Y + BORDER), BACKGROUND_COLOR);
}

void
	draw_border(t_cub *s)
{
	int	x;
	int	y;

	x = 0;
	while (x < MINIMAP_W + (2 * BORDER))
	{
		y = 0;
		while (y < MINIMAP_H + (2 * BORDER))
		{
			if ((x <= BORDER || x > MINIMAP_W)
				|| (y <= BORDER || y > MINIMAP_H))
				__put_pixel_on_img(&s->img, x + PADDING_X,
					y + PADDING_Y, BORDER_COLOR);
			y++;
		}
		x++;
	}
}

void
	draw_player(t_cub *s)
{
	int	x_cent;
	int	y_cent;

	x_cent = MINIMAP_W / 2 - 2;
	while (x_cent < ((MINIMAP_W / 2) + 2))
	{
		y_cent = MINIMAP_H / 2 - 2;
		while (y_cent < ((MINIMAP_H / 2) + 2))
		{
			__put_pixel_on_img(&s->img, x_cent + PADDING_X + BORDER,
				y_cent + PADDING_X + BORDER, PLAYER_COLOR);
			y_cent++;
		}
		x_cent++;
	}
}

void
	map2d(t_cub *s)
{
	int	pxl_x;
	int	pxl_y;

	pxl_x = 0;
	draw_border(s);
	while (pxl_x < MINIMAP_W)
	{
		pxl_y = 0;
		while (pxl_y < MINIMAP_H)
		{
			draw_elem(s, pxl_x, pxl_y);
			pxl_y++;
		}
		pxl_x++;
	}
	draw_player(s);
}
