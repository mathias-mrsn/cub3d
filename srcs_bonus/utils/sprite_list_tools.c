/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_list_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:39:12 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/23 12:59:28 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite
	*create_sprite(void)
{
	t_sprite	*current;

	current = NULL;
	current = __malloc(sizeof(t_sprite), SPRITE_STACK);
	return (current);
}

void
	add_sprite_back(t_sprite **head, t_sprite *new)
{
	t_sprite	*tmp;

	tmp = (*head);
	if (!tmp)
	{
		(*head) = new;
		return ;
	}
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
	}
}

void
	add_sprite_front(t_sprite **head, t_sprite *new)
{
	new->next = (*head);
	(*head) = new;
}
