/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:50:13 by mamaurai          #+#    #+#             */
/*   Updated: 2022/02/27 13:44:57 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_D_H
# define CUB3D_D_H

# define PROGRAM_NAME "cub3d"

# define NBR_WALL_SIDES	4
# define NBR_ARGS 8

# define NORTH_SIDE 0
# define EST_SIDE 1
# define SOUTH_SIDE 2
# define WEST_SIDE 3

# define SAVE_OPTION "--save"

/*
**	MEMORY STACKS
*/

# define PARSER_STACK		2
# define SINGLETON_STACK	42
# define TRASH_STACK		127

/*
**	WINDOW
*/

# define WIN_X_MAX			2000
# define WIN_Y_MAX			1500

#endif