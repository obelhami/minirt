#include "minirt.h"

void	add_object(t_object_container **world, t_object_container *new_object)
{
	t_object_container  *tmp;

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
	t_object_container  *node;

	node = malloc(sizeof(t_object_container));
	if (node == NULL)
		return (NULL);
	node->type = type;
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
		if (world->type == SPHERE)
		{
			if (hit_sphere((t_sphere *)world->object, interval, rec, ray))
			{
				hit_anything = TRUE;
				interval.max = rec->t;
			}
		}
		else if (world->type == CYLINDER)
		{
			if (hit_cylinder((t_cylinder *)world->object, interval, rec, ray))
			{
				hit_anything = TRUE;
				interval.max = rec->t;
			}
		}
		else if (world->type == PLANE)
		{
			if (hit_plane((t_plane *)world->object, interval, rec, ray))
			{
				hit_anything = TRUE;
				interval.max = rec->t;
			}
		}
		world = world->next;
	}
	return (hit_anything);
}
