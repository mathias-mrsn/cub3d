/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:50:13 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/01 14:37:35 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_D_H
# define CUB3D_D_H

# define PROGRAM_NAME "cub3d"

# define NBR_WALL_SIDES	4
# define NBR_ARGS 8

# define SAVE_OPTION "--save"
# define MAP_CHARSET " 012 NSEW"

/*
**	MEMORY STACKS
*/

# define PARSER_STACK		2
# define RAYCASTING_STACK	3
# define SINGLETON_STACK	42
# define TRASH_STACK		127

/*
**	WINDOW
*/

# define T_PI_4 	0.78539816339744830961566084581987572
# define T_PI_2 	1.57079632679489661923132169163975144
# define T_PI 		3.14159265358979323846264338327950288
# define T_3PI_2	4.71238898038468967399694520281627774
# define T_2PI 		6.28318530717958623199592693708837032

# define WIN_X_MAX			2000
# define WIN_Y_MAX			1500

#endif