/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_s.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:49:56 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/21 15:36:13 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_S_H
# define CUB3D_S_H

enum {
	NORTH_SIDE,
	EST_SIDE,
	SOUTH_SIDE,
	WEST_SIDE,
	DOOR
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
	char			*door_path;
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
	t_boolean		vert : 1;
	t_boolean		hit_door : 1;
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
	t_boolean		is_hit : 1;
	const struct s_door	*door;
}			t_ray;


typedef struct s_raycasting
{
	t_boolean		is_up : 1;
	t_boolean		is_left : 1;
	t_boolean		hit_door : 1;
	t_boolean		vert : 1;
	double			dirx;
	double			distance;
	double			init_angle;
	uint32_t		wall_type;
	double			hit_x;
	double			hit_y;
	uint32_t		col;
	const struct s_sprite		*head;
	const struct s_door			*door;
}			t_raycasting;

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

typedef struct s_moves
{
	t_boolean	m_forward : 1;
	t_boolean	m_back : 1;
	t_boolean	m_left : 1;
	t_boolean	m_right : 1;
	t_boolean	l_left : 1;
	t_boolean	l_right : 1;
	t_boolean	fire : 1;
	int			last_x_mouse;
	int			last_y_mouse;
}			t_moves;

typedef struct	s_door
{
	double		x;
	double		y;
	t_boolean	is_open; // 0 -> close | 1 -> is opening | 2 -> is open | 3 -> is closing
	double		opening_x; 
	clock_t		start;	 // the moment when the door started opening
}				t_door;

typedef struct s_gun
{
	// char		*gun_paths[NBR_GUN_SPRITE];
	t_img		gun_txtr[NBR_GUN_SPRITE];
	uint32_t	gun_state;
	clock_t		time;
	t_boolean	can_kill;
}				t_gun;

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
	t_door			*doors;
	t_gun			*gun;
	char			*filename;
	uint32_t		sprite_to_print;
	uint32_t		nbr_door;
	clock_t			time;
}			t_cub;

#endif