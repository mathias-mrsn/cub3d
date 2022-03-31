/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_f.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:50:05 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/31 08:51:51 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_F_H
# define CUB3D_F_H

/*
**	PARSING
*/

t_boolean			__check_args__(int ac, char **av, t_cub *s);
t_boolean			parsing(t_cub *s);
void				args_data_is_good(t_cub *s, char *str,
						uint8_t type_nbr, ssize_t idx);
void				get_map(t_cub *s, ssize_t *idx);
void				check_map_charset(t_cub *s);
void				check_map_walls(t_cub *s);
void				is_player_in(t_cub *s);
void				open_textures(t_cub *s);
void				stock_doors(t_cub *s);

/*
**	ENGINE
*/

int					engine(t_cub *s);
void				init_ray(t_cub *s, t_raycasting *rayc, t_ray *ray);
void				init_raycasting(t_cub *s, t_raycasting *rayc, int col);
void				compute_distance(t_raycasting *rayc,
						t_ray *hor, t_ray *ver);
void				put_ray_on_img(t_cub *s, t_raycasting *rayc, int col);
void				cast_ray(t_cub *s, t_raycasting *rayc);
void				ray_hit_wall(t_cub *s, t_raycasting *rayc,
						t_ray *ray, char *limiters);

/*
**	SINGLETON
*/

t_cub				*s(void);

/*
**	ERRORS
*/

void				__file_ext_error__(char *file);
void				__wrong_arg_nbr__(int ac);
void				__wrong_option__(char *option);
void				__file_cant_be_opened__(char *str);
void				__sprite_error__(char *str);

void				__color_error__(t_cub *s, ssize_t idx);
void				__resolution_error__(t_cub *s, ssize_t idx);
void				__texture_error__(t_cub *s, ssize_t idx,
						t_boolean error_type, char *str);
void				__print_error_line__(t_cub *s, ssize_t error_line);

void				__duplicate_data_error__(t_cub *s, ssize_t idx);
void				__invalid_info__(t_cub *s, ssize_t idx);
void				__data_missing_error__(t_cub *s);
void				__unable_to_open_xpm__(int line, char *file);

void				__extra_map_error__(t_cub *s, ssize_t idx);
void				__invalid_char__(t_cub *s, size_t line, size_t nbr);
void				__no_player_error__(void);
void				__leak_on_map_error__(t_cub *s, size_t line, size_t nbr);

/*
**	MATH
*/

double				__pythagore__(double x1, double y1, double x2, double y2);

/*
**	MOVES
*/

void				moves(t_cub *s);
int					key_handler(int key, t_cub *s);
int					key_release(int keycode, t_cub *s);
void				mouse_move(t_cub *s);
int					mouse_handler(int action);
int					mouse_release(int action);

/*
**	QUIT
*/

int					quit(int exit_code);

/*
**	UTILS
*/

double				trigo_cercle(double angle);
double				get_decimal(double nbr);

/*
**	SPRITE
*/

t_sprite			*create_sprite(void);
void				add_sprite_back(t_sprite **head, t_sprite *new);
void				add_sprite_front(t_sprite **head, t_sprite *new);
void				add_sprite(t_sprite **head, t_sprite *new);
void				put_sprite_on_img(t_cub *s, t_raycasting *rayc, int col);
void				sprite_dir(t_cub *s, char *str,
						ssize_t idx, uint8_t type_nbr);
void				init_new_sprite(t_cub *s, t_raycasting *rayc, t_ray *ray);
void				kill_sprite(t_cub *s, t_raycasting *rayc);
void				set_error_sprite(t_raycasting *rayc);
void				update_sprite_to_print(t_cub *s);

/*
**	GUN
*/

void				init_gun_textures(t_cub *s);
void				put_gun_on_img(t_cub *s, double i, double j);
void				update_gun_sprite(t_cub *s);
void				put_gun_cursor(t_cub *s);
void				kill_sprite(t_cub *s, t_raycasting *rayc);

/*
** MINIMAP
*/

void				map2d(t_cub *s);

/*
**	DOOR
*/

void				update_doors(t_cub *s);
int					through_door(t_cub *s, t_ray *ray, int y, int x);

#endif