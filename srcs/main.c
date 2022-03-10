/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:05:34 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/10 15:43:17 by mamaurai         ###   ########.fr       */
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

int
	key_handler(int key, t_cub *s)
{
	(void)s;
	if (key == KEY_UP)
		s->moves->m_forward = 1;
	else if (key == KEY_DOWN)
		s->moves->m_back = 1;
	else if (key == KEY_LEFT)
		s->moves->m_left = 1;
	else if (key == KEY_RIGHT)
		s->moves->m_right = 1;
	else if (key == KEY_D_LEFT)
		s->moves->l_left = 1;
	else if (key == KEY_D_RIGHT)
		s->moves->l_right = 1;
	else if (key == KEY_ESC)
		quit();
	return (1);
}

int
	mouse_handler(int key, t_cub *s)
{
	(void)s;
	printf("%d\n", key);
	return (1);
}

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
	cub->win = mlx_new_window(cub->mlx, cub->win_x, cub->win_y, PROGRAM_NAME);
	cub->img.ptr = mlx_new_image(cub->mlx, cub->win_x, cub->win_y);
	cub->img.addr = mlx_get_data_addr(cub->img.ptr, &cub->img.bpp, &cub->img.size_line, &cub->img.endian);
	engine(cub);
	mlx_mouse_hook(cub->win, mouse_handler, cub);
	mlx_hook(cub->win, 2, (1L << 0), key_handler, cub);
	mlx_hook(cub->win, 3, (1L << 1), NULL, NULL);
	mlx_hook(cub->win, 17, 0, quit, NULL);
	mlx_loop_hook(cub->mlx, &engine, cub);
	mlx_loop(cub->mlx);

}
