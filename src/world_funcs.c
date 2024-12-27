/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:18:53 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/27 16:34:39 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_object(t_object_container **world, t_object_container *new_object)
{
	t_object_container	*tmp;

	if (world == NULL)
		return ;
	if (*world == NULL)
		*world = new_object;
	else
	{
		tmp = *world;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_object;
	}
}

t_object_container	*create_object(int type, void *object)
{
	t_object_container	*node;

	node = malloc(sizeof(t_object_container));
	if (node == NULL)
		return (NULL);
	node->type = type;
	if (type == SPHERE)
		node->hit = hit_sphere;
	else if (type == CYLINDER)
		node->hit = hit_cylinder;
	else if (type == PLANE)
		node->hit = hit_plane;
	node->object = object;
	node->next = NULL;
	return (node);
}

BOOL	hit_any_object(t_object_container *world, t_interval interval,
		t_hit_record *rec, t_ray *ray)
{
	BOOL			hit_anything;

	hit_anything = FALSE;
	while (world != NULL)
	{
		if (world->hit(world->object, interval, rec, ray))
		{
			hit_anything = TRUE;
			interval.max = rec->t;
		}
		world = world->next;
	}
	return (hit_anything);
}
