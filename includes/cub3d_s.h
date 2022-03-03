/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_s.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:49:56 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/03 14:11:52 by mamaurai         ###   ########.fr       */
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
}			t_parser;

typedef struct s_ray
{
	t_boolean		vert : 2;
	double			distance;
	double			angle;
	double			x;
	double			y;
	double			cos_angle;
	double			x_to_add;
	double			y_to_add;
	double			sin;
	t_boolean		is_hit;	
}			t_ray;

typedef struct __attribute__((packed)) s_raycasting
{
	t_boolean		is_up : 2;
	t_boolean		is_left : 2;
	double			dirx;
	double			distance;
	// double			angle;
	double			init_angle;
	uint8_t			wall_type;
	t_ray			vertical;
	t_ray			horizontal;
	double			hit_x;
	double			hit_y;
}			t_raycasting;

typedef struct s_cub
{
	void			*mlx;
	void			*win;
	t_img			img;
	size_t			map_width;
	size_t			map_height;
	int				win_x;
	int				win_y;
	char			**map;
	t_boolean		save;
	t_parser		*parser;
	t_player		*player;
	t_textures		*textures;
	char			*filename;
}			t_cub;

#endif