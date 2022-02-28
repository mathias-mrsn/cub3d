/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_s.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:49:56 by mamaurai          #+#    #+#             */
/*   Updated: 2022/02/28 14:28:12 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_S_H
# define CUB3D_S_H

enum {
	NORTH_SIDE,
	EST_SIDE,
	SOUTH_SIDE,
	WEST_SIDE
};

typedef struct s_player
{
	double	p_x;
	double	p_y;
	double	angle;
}			t_player;

typedef struct s_textures
{
	t_img	walls[NBR_WALL_SIDES];
	int		floor;
	int		ceil;
}			t_textures;

typedef struct s_parser
{
	t_boolean		error;
	char			*walls_path[NBR_WALL_SIDES];
	t_boolean		check[NBR_ARGS];
	int				floor;
	int				ceil;
	char			**file;
	char			**map;
	int				fd;
	int				win_x;
	int				win_y;
}			t_parser;

typedef struct s_cub
{
	void			*mlx;
	void			*win;
	char			**map;
	t_boolean		save;
	t_parser		*parser;
	t_player		*player;
	t_textures		*textures;
	char			*filename;
}			t_cub;

#endif