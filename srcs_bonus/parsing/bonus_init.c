/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:41:36 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/23 13:08:31 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	init_gun_textures(t_cub *s)
{
	uint32_t	idx;
	const char	*gun_paths[NBR_GUN_SPRITE] = {
		"./textures/gun_assets/01.xpm",
		"./textures/gun_assets/02.xpm",
		"./textures/gun_assets/03.xpm",
		"./textures/gun_assets/04.xpm",
		"./textures/gun_assets/05.xpm",
		"./textures/gun_assets/06.xpm"};

	idx = 0;
	while (idx < NBR_GUN_SPRITE)
	{
		s->gun->gun_txtr[idx].ptr = mlx_xpm_file_to_image(s->mlx,
				(char *)gun_paths[idx], &s->gun->gun_txtr[idx].x,
				&s->gun->gun_txtr[idx].y);
		if (NULL == s->gun->gun_txtr[idx].ptr)
			__unable_to_open_xpm__(__LINE__, __FILE__);
		s->gun->gun_txtr[idx].addr
			= mlx_get_data_addr(s->gun->gun_txtr[idx].ptr,
				&s->gun->gun_txtr[idx].bpp, &s->gun->gun_txtr[idx].size_line,
				&s->gun->gun_txtr[idx].endian);
		if (NULL == s->gun->gun_txtr[idx].addr)
			__unable_to_open_xpm__(__LINE__, __FILE__);
		idx++;
	}
}

void
	__sort_args__(char ***list)
{
	size_t	idx;

	idx = 0;
	while ((*list)[idx] && (*list)[idx + 1])
	{
		if (__strcmp((*list)[idx], (*list)[idx + 1]) > 0)
		{
			__memswap((void **)&(*list)[idx], (void **)&(*list)[idx + 1]);
			idx = 0;
		}
		else
			idx++;
	}
}

void
	__get_list__(char ***list, DIR *dir, char *path)
{
	struct dirent	*dirent;
	char			*new_path;

	dirent = __malloc(sizeof(struct dirent), 1);
	dirent = readdir(dir);
	while (dirent)
	{
		if (dirent->d_name[0] != '.'
			&& __file_extention(dirent->d_name, ".xpm"))
		{
			new_path = __strjoin(path, "/");
			__strs_add_back(list, __strjoin(new_path, dirent->d_name));
		}
		dirent = readdir(dir);
	}
	__free(dirent);
}

void
	stock_doors(t_cub *s)
{
	size_t			i;
	size_t			j;
	size_t			idx;

	idx = 0;
	if (0 == s->nbr_door)
		return ;
	s->doors = __malloc(sizeof(t_door) * s->nbr_door, PARSER_STACK);
	i = 0;
	while (i < __strslen(s->map))
	{
		j = -1;
		while (++j < __strlen(s->map[i]))
		{
			if (s->map[i][j] == 'D')
			{
				s->doors[idx].x = j + 0.5;
				s->doors[idx].y = i + 0.5;
				idx++;
			}
		}
		i++;
	}
}

void
	sprite_dir(t_cub *s, char *str, ssize_t idx, uint8_t type_nbr)
{
	DIR		*dir;
	char	**list;

	(void)s;
	(void)type_nbr;
	(void)idx;
	printf("path = %s\n", str);
	list = NULL;
	dir = opendir(str);
	if (NULL == dir)
	{
		__texture_error__(s, idx, 1, str);
		return ;
	}
	__get_list__(&list, dir, str);
	__sort_args__(&list);
	s->parser->sprite_path = list;
	s->parser->nbr_sprite = __strslen(list);
	free(dir);
}
