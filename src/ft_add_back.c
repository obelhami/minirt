#include "minirt.h"

void    add_object(t_object_container **world, t_object_container *new_object)
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

t_object_container  *create_object(int type, void *object)
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
