/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:03:53 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/23 17:02:59 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	set_error_sprite(t_raycasting *rayc)
{
	t_sprite	*tmp;

	tmp = (t_sprite *)rayc->head;
	while (tmp)
	{
		if (rayc->distance < tmp->distance_fc)
			tmp->error = true;
		tmp = tmp->next;
	}
}

void
	kill_sprite(t_cub *s, t_raycasting *rayc)
{
	t_sprite	*tmp;
	const t_img	txtr = s->textures->sprite[s->sprite_to_print];
	int			x;
	int			y;

	x = 0;
	y = 0;
	tmp = (t_sprite *)rayc->head;
	while (tmp)
	{
		if (tmp->error == false && s->gun->can_kill
			&& (*((uint32_t *)(txtr.addr
					+ ((((txtr.y / 2) * txtr.bpp / 8) * txtr.y))
					+ (int)(tmp->texture_x * txtr.x) * \
				txtr.bpp / 8)) != 0))
		{
			x = (int)tmp->x;
			y = (int)tmp->y;
		}
		tmp = tmp->next;
	}
	if (x && y)
		s->map[y][x] = '0';
}

void
	init_new_sprite(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	t_sprite	*new;

	new = create_sprite();
	new->hit_x = ray->x;
	new->hit_y = ray->y;
	new->x = __trnd((ray->vert), ((int)ray->x - rayc->is_left + 0.5),
			((int)(ray->x) + 0.5));
	new->y = __trnd((ray->vert), ((int)ray->y + 0.5),
			((int)ray->y - rayc->is_up + 0.5));
	new->distance_fc = __pythagore(s->player->p_x,
			s->player->p_y, new->x, new->y);
	new->acos = acos((new->x - s->player->p_x) / new->distance_fc);
	new->sin = ((new->y - s->player->p_y) / new->distance_fc);
	new->angle_initial = trigo_cercle(new->acos * \
		__trnd((new->sin > 0), -1, 1));
	new->angle_view_sprite = rayc->dirx - new->angle_initial;
	new->hypothenus = new->distance_fc / cos(new->angle_view_sprite);
	new->adj = sqrt(pow(new->hypothenus, 2) - pow(new->distance_fc, 2));
	if (new->adj > 0.5)
		return ;
	new->texture_x = __trnd((new->angle_view_sprite < 0),
			(0.5 - new->adj), (0.5 + new->adj));
	if (new->adj <= 0.5)
		add_sprite_front((t_sprite **)&rayc->head, new);
}

void
	update_sprite_to_print(t_cub *s)
{
	clock_t		now;
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
