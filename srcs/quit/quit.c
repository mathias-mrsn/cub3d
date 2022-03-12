/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:17:55 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/12 12:19:27 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	quit(void)
{
	mlx_destroy_image(s()->mlx, s()->textures->walls[0].ptr);
	mlx_destroy_image(s()->mlx, s()->textures->walls[1].ptr);
	mlx_destroy_image(s()->mlx, s()->textures->walls[2].ptr);
	mlx_destroy_image(s()->mlx, s()->textures->walls[3].ptr);
	mlx_destroy_image(s()->mlx, s()->img.ptr);
	mlx_destroy_window(s()->mlx, s()->win);
	free(s()->mlx);
	__clean_all();
	exit(1);
	return (1);
}
