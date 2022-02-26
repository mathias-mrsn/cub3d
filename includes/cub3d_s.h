/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_s.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:49:56 by mamaurai          #+#    #+#             */
/*   Updated: 2022/02/26 17:03:04 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_S_H
# define CUB3D_S_H

typedef struct s_player
{
	double	p_x;
	double	p_y;
	double	angle;
}			t_player;

typedef struct s_textures
{
	char	*walls_path[NBR_WALL_SIDES];
	t_img	walls[NBR_WALL_SIDES];
	int		floor;
	int		ceil;
}			t_textures;

typedef struct s_parser
{
	t_boolean		error;
	char			*walls_path[NBR_WALL_SIDES];
	t_boolean		is_walls[NBR_WALL_SIDES];
	int				floor;
	t_boolean		is_floor;
	int				ceil;
	t_boolean		is_ceil;
	char			**file;
	char			**map;
	int				fd;
}			t_parser;

typedef struct s_cub
{
	char			**map;
	t_boolean		save;
	t_parser		*parser;
	t_player		*player;
	t_textures		*textures;
	char			*filename;
}			t_cub;

#endif