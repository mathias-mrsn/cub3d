/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:36:07 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/17 16:47:36 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_door_texture(t_cub *s)
{
	__memset(&s->textures->door, 0, sizeof(t_img));
	s->textures->door.ptr = mlx_xpm_file_to_image(s->mlx, DOOR_TEXTURE,
	&s->textures->door.x, &s->textures->door.y);
	if (NULL == s->textures->door.ptr)
		__unable_to_open_xpm__(__LINE__, __FILE__);
	s->textures->door.addr = mlx_get_data_addr(s->textures->door.ptr,
	&s->textures->door.bpp, &s->textures->door.size_line,
	&s->textures->door.endian);
	if (NULL == s->textures->door.addr)
		__unable_to_open_xpm__(__LINE__, __FILE__);
}

void	open_sprite_texture(t_cub *s)
{
	__memset(&s->textures->sprite, 0, sizeof(t_img));
	s->textures->sprite.ptr = mlx_xpm_file_to_image(s->mlx, "sprite.xpm",
	&s->textures->sprite.x, &s->textures->sprite.y);
	if (NULL == s->textures->sprite.ptr)
	__unable_to_open_xpm__(__LINE__, __FILE__);
	s->textures->sprite.addr = mlx_get_data_addr(s->textures->sprite.ptr,
	&s->textures->sprite.bpp, &s->textures->sprite.size_line,
	&s->textures->sprite.endian);
	if (NULL == s->textures->sprite.addr)
	__unable_to_open_xpm__(__LINE__, __FILE__);
}

void
	open_textures(t_cub *s)
{
	uint8_t	idx;

	idx = 0;
	while (idx < NBR_WALL_SIDES)
	{
		__memset(&s->textures->walls[idx], 0, sizeof(t_img));
		s->textures->walls[idx].ptr = mlx_xpm_file_to_image(s->mlx,
				s->parser->walls_path[idx], &s->textures->walls[idx].x,
				&s->textures->walls[idx].y);
		if (NULL == s->textures->walls[idx].ptr)
			__unable_to_open_xpm__(__LINE__, __FILE__);
		s->textures->walls[idx].addr
			= mlx_get_data_addr(s->textures->walls[idx].ptr,
				&s->textures->walls[idx].bpp,
				&s->textures->walls[idx].size_line,
				&s->textures->walls[idx].endian);
		if (NULL == s->textures->walls[idx].addr)
			__unable_to_open_xpm__(__LINE__, __FILE__);
		idx++;
	}
	s->textures->ceil = s->parser->ceil;
	s->textures->floor = s->parser->floor;
	open_door_texture(s);
	open_sprite_texture(s);
}
