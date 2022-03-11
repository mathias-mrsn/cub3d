/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:50:13 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/11 09:56:45 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_D_H
# define CUB3D_D_H

# define PROGRAM_NAME "cub3d"

# define NBR_WALL_SIDES	4
# define NBR_ARGS 8

# define SAVE_OPTION "--save"
# define MAP_CHARSET "012 NSEW"

/*
**	MEMORY STACKS
*/

# define PARSER_STACK		2
# define RAYCASTING_STACK	3
# define SINGLETON_STACK	42
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
# else
#  define KEY_D_LEFT 65361
#  define KEY_D_RIGHT 65363
#  define KEY_ESC		65307
#  define KEY_UP		119
#  define KEY_RIGHT	97
#  define KEY_DOWN		115
#  define KEY_LEFT		100
#  define RED_CROSS	33
# endif

/*
**	WINDOW
*/



# define FOV 1.15192

# define CAMERA_SPEED 0.05
# define MOVING_DISTANCE 0.15

# define WIN_X_MAX			2000
# define WIN_Y_MAX			1500

/*
**	BONUS
*/

# define SKY_TEXTURE "./textures/sky/star_sky.xpm"

# define LIFE_BAR_HEIGHT 40
# define LIFE_BAR_WIDTH 100

#endif