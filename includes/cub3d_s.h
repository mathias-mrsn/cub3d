/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_s.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:49:56 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/18 09:55:55 by mamaurai         ###   ########.fr       */
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

enum {
	MOVE_FORWARD,
	MOVE_RIGHT,
	MOVE_BACK,
	MOVE_LEFT,
	LOOK_LEFT,
	LOOK_RIGHT
};

typedef struct s_player
{
	double		p_x;
	double		p_y;
	double		angle;
}			t_player;

typedef struct s_textures
{
	t_img	walls[NBR_WALL_SIDES];
	t_img	*sprite;
	t_img	door;
	int		floor;
	int		ceil;
}			t_textures;

typedef struct s_parser
{
	t_boolean		error;
	char			*walls_path[NBR_WALL_SIDES];
	char			**sprite_path;
	uint32_t		nbr_sprite;
	t_boolean		check[NBR_ARGS];
	int				floor;
	int				ceil;
	char			**file;
	char			**map;
	int				fd;
}			t_parser;

typedef struct __attribute__((packed)) s_ray
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
	double			cos;
	double			tan;
	t_boolean		is_hit;	
}			t_ray;

typedef struct __attribute__((packed)) s_sprite
{
	t_boolean	error;
	double	hit_x;
	double	hit_y;
	double	x;
	double	y;
	double	distance_fc;
	double	angle_initial;
	double	angle_view_sprite;
	double 	hypothenus;
	double	adj;
	double	sin;
	double	acos;
	double	texture_x;
	struct s_sprite *next;
}			t_sprite;

typedef struct s_raycasting
{
	t_boolean		is_up : 2;
	t_boolean		is_left : 2;
	double			dirx;
	double			distance;
	double			init_angle;
	uint32_t		wall_type;
	t_ray			vertical;
	t_ray			horizontal;
	double			hit_x;
	double			hit_y;
	t_sprite		*head;
}			t_raycasting;

typedef struct s_moves
{
	t_boolean	m_forward : 1;
	t_boolean	m_back : 1;
	t_boolean	m_left : 1;
	t_boolean	m_right : 1;
	t_boolean	l_left : 1;
	t_boolean	l_right : 1;
	int			last_x_mouse;
	int			last_y_mouse;
}			t_moves;

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
	t_moves			*moves;
	char			*filename;
	uint32_t		sprite_to_print;
	clock_t			time;
}			t_cub;

#endif