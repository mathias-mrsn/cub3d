/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:17:55 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/22 10:38:54 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	quit(void)
{
	int i;

	i = 0;
	while (i < NBR_WALL_SIDES)
		mlx_destroy_image(s()->mlx, s()->textures->walls[i++].ptr);
	i = 0;
	while (i < NBR_GUN_SPRITE)
		mlx_destroy_image(s()->mlx, s()->gun->gun_txtr[i++].ptr);
	i = 0;
	while (i < s()->parser->nbr_sprite)
		mlx_destroy_image(s()->mlx, s()->textures->sprite[i++].ptr);
	mlx_destroy_image(s()->mlx, s()->img.ptr);
	mlx_destroy_window(s()->mlx, s()->win);
	free(s()->mlx);
	__clean_all();
	exit(1);
	return (1);
}
