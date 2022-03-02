/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:05:34 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/02 09:51:49 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	main(int ac, char **av)
{
	t_cub *cub = s();

	(void)cub;
	cub->mlx = mlx_init();
	if (NULL == cub->mlx)
		return (EXIT_FAILURE); //mlx start error
	if (__FAILURE == __check_args__(ac, av, cub))
		__exit(EXIT_FAILURE);
	if (__FAILURE == parsing(cub))
		__exit(EXIT_FAILURE);
	// cub->win = mlx_new_window(cub->mlx, cub->win_x, cub->win_y, PROGRAM_NAME);
	// cub->img.ptr = mlx_new_image(cub->mlx, cub->win_x, cub->win_y);
	// cub->img.addr = mlx_get_data_addr(cub->img.ptr, &cub->img.bpp, &cub->img.size_line, &cub->img.endian);
	engine(cub);
	__clean(PARSER_STACK);
	__clean_all();
}