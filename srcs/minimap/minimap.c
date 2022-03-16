/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:53:28 by malouvar          #+#    #+#             */
/*   Updated: 2022/03/16 13:50:13 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_elem(t_cub *s, int y, int x, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= 2)
	{
		j = 0;
		while (j <= 2)
		{
			__put_pixel_on_img(&s->img, MINIMAP_OFFSET_X + (x * 4) + i,
				MINIMAP_OFFSET_Y + (y * 4) + j, color);
			j++;
		}
		i++;
	}
}

void	map2d(t_cub *s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == '1')
				draw_elem(s, y, x, WALL_COLOR);
			else if (s->map[y][x] == '0' || s->map[y][x] == '2')
				draw_elem(s, y, x, EMPTY_COLOR);
			x++;
		}
		y++;
	}
	draw_elem(s, s->player->p_y, s->player->p_x, PLAYER_COLOR);
}
