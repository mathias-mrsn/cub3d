/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:50:13 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/31 15:49:58 by mamaurai         ###   ########.fr       */
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
#  define CMD_PLAY_SOUND "afplay"
#  define KEY_T		3
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
#  define CMD_PLAY_SOUND "aplay"
#  define KEY_T		102
# endif

/*
**	WINDOW
*/

# define WIN_X_MAX			2000
# define WIN_Y_MAX			1500

/*
**	SOUNDS
*/

# define SOUND_DOOR_PATH	"sounds/Door.wav"
# define SOUND_GUN_PATH		"sounds/Pistol.wav"

/*
**	GUN
*/

# define NBR_GUN_SPRITE		6

/*
**	MOUSE
*/

# define RAD_PER_PIXEL		0.0025

/*
**	GAME SETTINGS
*/

# define FOV 1.15192
# define CAMERA_SPEED 0.04
# define MOVING_DISTANCE 0.06
# define SPRITE_INTERVAL 100000

/*
**	BONUS
*/

# define DOOR_TEXTURE "./textures/door.xpm"
# define OPENING_DOOR_DIST	3.5
# define DOOR_OPENING_SPEED 0.005

/*
**	MINIMAP
*/

# define PADDING_X	50
# define PADDING_Y	50
# define MINIMAP_H	100
# define MINIMAP_W	200
# define CENTER_X	100
# define CENTER_Y	50
# define DIST_PER_PIXEL	0.15
# define BORDER			3

# define BACKGROUND_COLOR	0x101010
# define WALL_COLOR			0xFFFFFF
# define DOOR_COLOR			0xfffe48
# define SPRITE_COLOR		0x55a155
# define BORDER_COLOR		0x303030
# define PLAYER_COLOR		0xf0f0f0

#endif