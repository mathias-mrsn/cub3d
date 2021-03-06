/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:05:34 by mamaurai          #+#    #+#             */
/*   Updated: 2022/04/05 10:29:55 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#if defined(__APPLE__) && defined(__MACH__)

int
	main(int ac, char **av)
{
	t_cub	*cub;

	cub = s();
	if (__FAILURE == __check_args__(ac, av, cub))
		__exit(EXIT_FAILURE);
	cub->mlx = mlx_init();
	if (NULL == cub->mlx)
		return (EXIT_FAILURE);
	mlx_do_key_autorepeaton(cub->mlx);
	if (__FAILURE == parsing(cub))
		__exit(EXIT_FAILURE);
	cub->win = mlx_new_window(cub->mlx, cub->win_x, cub->win_y, PROGRAM_NAME);
	cub->img.ptr = mlx_new_image(cub->mlx, cub->win_x, cub->win_y);
	cub->img.addr = mlx_get_data_addr(cub->img.ptr,
			&cub->img.bpp, &cub->img.size_line, &cub->img.endian);
	mlx_mouse_hide();
	mlx_mouse_move(cub->win, cub->win_x / 2, cub->win_y / 2);
	mlx_hook(cub->win, 4, (0L), mouse_handler, cub);
	mlx_hook(cub->win, 5, (0L), mouse_release, cub);
	mlx_hook(cub->win, 2, (1L << 0), key_handler, cub);
	mlx_hook(cub->win, 3, (1L << 1), key_release, cub);
	mlx_hook(cub->win, 17, 0, quit, EXIT_SUCCESS);
	mlx_loop_hook(cub->mlx, &engine, cub);
	mlx_loop(cub->mlx);
}

#else

int
	main(int ac, char **av)
{
	t_cub	*cub;

	cub = s();
	cub->mlx = mlx_init();
	if (NULL == cub->mlx)
		return (EXIT_FAILURE);
	mlx_do_key_autorepeaton(cub->mlx);
	if (__FAILURE == __check_args__(ac, av, cub))
		__exit(EXIT_FAILURE);
	if (__FAILURE == parsing(cub))
		__exit(EXIT_FAILURE);
	cub->win = mlx_new_window(cub->mlx, cub->win_x, cub->win_y, PROGRAM_NAME);
	cub->img.ptr = mlx_new_image(cub->mlx, cub->win_x, cub->win_y);
	cub->img.addr = mlx_get_data_addr(cub->img.ptr,
			&cub->img.bpp, &cub->img.size_line, &cub->img.endian);
	mlx_mouse_hide(cub->mlx, cub->win);
	mlx_mouse_move(cub->mlx, cub->win, cub->win_x / 2, cub->win_y / 2);
	mlx_hook(cub->win, 4, (0L), mouse_handler, cub);
	mlx_hook(cub->win, 5, (0L), mouse_release, cub);
	mlx_hook(cub->win, 2, (1L << 0), key_handler, cub);
	mlx_hook(cub->win, 3, (1L << 1), key_release, cub);
	mlx_hook(cub->win, 17, 0, quit, EXIT_SUCCESS);
	mlx_loop_hook(cub->mlx, &engine, cub);
	mlx_loop(cub->mlx);
}

#endif
