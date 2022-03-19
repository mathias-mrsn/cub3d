/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:50:13 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/19 18:35:55 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_D_H
# define CUB3D_D_H

# define PROGRAM_NAME "cub3d"

# define NBR_WALL_SIDES	5
# define NBR_ARGS 9

# define SAVE_OPTION "--save"
# define MAP_CHARSET "012 DNSEW"

/*
**	MEMORY STACKS
*/

# define PARSER_STACK		2
# define RAYCASTING_STACK	3
# define SINGLETON_STACK	42
# define SPRITE_STACK		50
# define TRASH_STACK		127

# if defined(__APPLE__) && defined(__MACH__)
#  define KEY_D_LEFT 123
#  define KEY_D_RIGHT 124
#  define KEY_ESC		53
#  define KEY_UP		13
#  define KEY_RIGHT	0
#  define KEY_DOWN		1
#  define KEY_LEFT		2
#  define RED_CROSS	17
#  define MAC 1
# else
#  define KEY_D_LEFT 65361
#  define KEY_D_RIGHT 65363
#  define KEY_ESC		65307
#  define KEY_UP		119
#  define KEY_RIGHT	97
#  define KEY_DOWN		115
#  define KEY_LEFT		100
#  define RED_CROSS	33
#  define MAC 0
# endif

/*
**	WINDOW
*/

# define WIN_X_MAX			2000
# define WIN_Y_MAX			1500

/*
**	MOUSE
*/

# define RAD_PER_PIXEL		0.0025

/*
**	GAME SETTINGS
*/

# define FOV 1.15192
# define CAMERA_SPEED 0.04
# define MOVING_DISTANCE 0.10
# define SPRITE_INTERVAL 100000
# define OPENING_DOOR_DIST	2.5
# define DOOR_OPENING_SPEED 0.10

/*
**	BONUS
*/

# define SKY_TEXTURE "./textures/sky/star_sky.xpm"
# define DOOR_TEXTURE "./textures/door.xpm"

# define LIFE_BAR_HEIGHT 40
# define LIFE_BAR_WIDTH 100

# define MINIMAP_OFFSET_X 21
# define MINIMAP_OFFSET_Y 21
# define EMPTY_COLOR 0XFFFFFF
# define WALL_COLOR 0X00FF00
# define PLAYER_COLOR 0XFF0000

#endif