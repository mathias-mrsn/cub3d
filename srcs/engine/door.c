/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:56:17 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/19 18:53:02 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define _CLOCK_TIME	10000

void
	open_door(t_door *door)
{
	if (door->is_open == 0)
	{
		door->is_open = 1;
		door->start = clock() / _CLOCK_TIME;
	}
	else if (door->is_open == 1)
	{
		door->opening_x += ((clock() / _CLOCK_TIME) - door->start) * DOOR_OPENING_SPEED;
		door->start = clock() / _CLOCK_TIME;
		if (door->opening_x >= 1.0)
		{
			door->is_open = 2;
			door->opening_x = 1.0;
		}
	}
	else if (door->is_open == 2)
		return;
	else
	{
		door->start = clock() / _CLOCK_TIME;
		door->is_open = 1;
	}
}

void
	close_door(t_door *door)
{
	if (door->is_open == 0)
		return;
	else if (door->is_open == 1)
	{
		door->start = clock() / _CLOCK_TIME;
		door->is_open = 3;
	}
	else if (door->is_open == 2)
	{
		door->is_open = 3;
		door->start = clock() / _CLOCK_TIME;
	}
	else
	{
		door->opening_x -= ((clock() / _CLOCK_TIME) - door->start) * DOOR_OPENING_SPEED;
		door->start = clock() / _CLOCK_TIME;
		if (door->opening_x <= 0)
		{
			door->is_open = 0;
			door->opening_x = 0;		
		}
	}
}

void
	update_doors(t_cub *s)
{
	uint32_t	idx;

	idx = 0;
	while (idx < s->nbr_door)
	{
		if (__pythagore(s->player->p_x, s->player->p_y, s->doors[idx].x, s->doors[idx].y) < OPENING_DOOR_DIST)
			open_door(&s->doors[idx]);
		else
			close_door(&s->doors[idx]);
		idx++;
	}
}