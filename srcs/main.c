/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:05:34 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/20 17:14:03 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	_print_parsing(void)
{
	printf("wall 0 = %s\n", s()->parser->walls_path[0]);
	printf("wall 1 = %s\n", s()->parser->walls_path[1]);
	printf("wall 2 = %s\n", s()->parser->walls_path[2]);
	printf("wall 3 = %s\n", s()->parser->walls_path[3]);
	printf("door = %s\n", s()->parser->walls_path[4]);
	printf("nbr_door = %d\n", s()->nbr_door);
}

int
	mouse_handler(int action, t_cub *ss)
{
	printf("%d\n", action);
	if (action == 1)
		s()->moves->fire = 1;
	return (0);
}

int
	mouse_release(int action, t_cub *ss)
{
	if (action == 1)
		s()->moves->fire = 0;
	return (0);
}

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
	_print_parsing();
	cub->win = mlx_new_window(cub->mlx, cub->win_x, cub->win_y, PROGRAM_NAME);
	cub->img.ptr = mlx_new_image(cub->mlx, cub->win_x, cub->win_y);
	cub->img.addr = mlx_get_data_addr(cub->img.ptr,
			&cub->img.bpp, &cub->img.size_line, &cub->img.endian);

# if defined(__APPLE__) && defined(__MACH__)
	mlx_mouse_move(cub->win, cub->win_x / 2, cub->win_y / 2);
# else
	mlx_mouse_move(cub->mlx, cub->win, cub->win_x / 2, cub->win_y / 2);
# endif

	mlx_hook(cub->win, 4, (0L), mouse_handler, cub);
	mlx_hook(cub->win, 5, (0L), mouse_release, cub);
	mlx_hook(cub->win, 2, (1L << 0), key_handler, cub);
	mlx_hook(cub->win, 3, (1L << 1), key_release, cub);
	mlx_hook(cub->win, 17, 0, quit, NULL);
	mlx_loop_hook(cub->mlx, &engine, cub);
	mlx_loop(cub->mlx);
}
