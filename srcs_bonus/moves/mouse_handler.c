/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:17:31 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/24 14:19:31 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	mouse_handler(int action)
{
	if (action == 1)
		s()->moves->fire = 1;
	return (0);
}

int
	mouse_release(int action)
{
	if (action == 1)
		s()->moves->fire = 0;
	return (0);
}
