/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:56:17 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/23 13:34:37 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define _CLOCK_TIME	10000

static void
	open_door(t_door *door)
{
	if (door->is_open == 0)
	{
		door->is_open = 1;
		door->start = clock() / _CLOCK_TIME;
		system(CMD_PLAY_SOUND" "SOUND_DOOR_PATH" 2>/dev/null&");
	}
	else if (door->is_open == 1)
	{
		door->opening_x += ((clock() / _CLOCK_TIME) - \
			door->start) * DOOR_OPENING_SPEED;
		door->start = clock() / _CLOCK_TIME;
		if (door->opening_x >= 1.0)
		{
			door->is_open = 2;
			door->opening_x = 1.0;
			system("killall "CMD_PLAY_SOUND" 2>/dev/null&");
		}
	}
	else if (door->is_open == 3)
	{
		door->start = clock() / _CLOCK_TIME;
		door->is_open = 1;
		system("killall "CMD_PLAY_SOUND" 2>/dev/null&");
		system(CMD_PLAY_SOUND" "SOUND_DOOR_PATH" 2>/dev/null&");
	}
}

static void
	close_door(t_door *door)
{
	if (door->is_open == 1)
	{
		door->start = clock() / _CLOCK_TIME;
		door->is_open = 3;
		system("killall "CMD_PLAY_SOUND" 2>/dev/null&");
		system(CMD_PLAY_SOUND" "SOUND_DOOR_PATH" 2>/dev/null&");
	}
	else if (door->is_open == 2)
	{
		door->is_open = 3;
		door->start = clock() / _CLOCK_TIME;
		system(CMD_PLAY_SOUND" "SOUND_DOOR_PATH" 2>/dev/null&");
	}
	else if (door->is_open == 3)
	{
		door->opening_x -= ((clock() / _CLOCK_TIME) - \
			door->start) * DOOR_OPENING_SPEED;
		door->start = clock() / _CLOCK_TIME;
		if (door->opening_x <= 0)
		{
			door->is_open = 0;
			door->opening_x = 0;
			system("killall "CMD_PLAY_SOUND" 2>/dev/null&");
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
		if (__pythagore(s->player->p_x, s->player->p_y, s->doors[idx].x,
				s->doors[idx].y) < OPENING_DOOR_DIST)
			open_door(&s->doors[idx]);
		else
			close_door(&s->doors[idx]);
		idx++;
	}
}

static t_door
	*door_at(t_cub *s, int y, int x)
{
	uint32_t	idx;

	idx = 0;
	while (idx < s->nbr_door)
	{
		if ((double)(y + 0.5) == s->doors[idx].y
				&& (double)(x + 0.5) == s->doors[idx].x)
			return (&s->doors[idx]);
		idx++;
	}
	return (NULL);
}

int
	through_door(t_cub *s, t_ray *ray, int y, int x)
{
	const t_door	*door = door_at(s, y, x);

	if (NULL == door)
		return (false);
	if (door->is_open == 0)
	{
		ray->door = door;
		ray->hit_door = 1;
		return (true);
	}
	else if (door->is_open == 1 || door->is_open == 3)
	{
		if ((ray->vert && get_decimal(ray->y) > door->opening_x)
			|| (!ray->vert && get_decimal(ray->x) > door->opening_x))
		{
			ray->door = door;
			ray->hit_door = 1;
			return (true);
		}
		else
			return (false);
	}
	if (door->is_open == 2)
		return (false);
	return (false);
}
