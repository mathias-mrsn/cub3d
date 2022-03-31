/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_list_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:39:12 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/31 14:59:30 by mamaurai         ###   ########.fr       */
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

void
	add_sprite(t_sprite **head, t_sprite *new)
{
	t_sprite	*tmp;
	t_sprite	*save;

	tmp = (*head);
	if (!tmp || new->distance_fc > tmp->distance_fc)
	{
		add_sprite_front(head, new);
		return ;
	}
	while (tmp)
	{
		if (tmp->next && new->distance_fc > tmp->next->distance_fc)
		{
			save = tmp->next;
			tmp->next = new;
			new->next = save;
			return ;
		}
		else if (!tmp->next)
		{
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
	}
}
