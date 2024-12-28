/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:09:31 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/28 21:09:32 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	**return_head(void)
{
	static t_list	*head;

	return (&head);
}

t_list	**return_tail(void)
{
	static t_list	*tail;

	return (&tail);
}

void	addback(t_list *node)
{
	t_list	**temp;

	temp = return_tail();
	if (temp == NULL)
		*temp = node;
	else
	{
		(*temp)->next = node;
		*temp = node;
	}
}

void	*safe_alloc(size_t size)
{
	void	*ptr;
	void	*node;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		perror("Fatal");
		garbage_collector();
		exit(1);
	}
	node = ft_lstnew(ptr);
	if (node == NULL)
	{
		perror("Fatal");
		garbage_collector();
		exit(1);
	}
	addback(node);
	return (ptr);
}

void	garbage_collector(void)
{
	t_list	*temp;
	t_list	**garbage;

	garbage = return_head();
	while (*garbage)
	{
		temp = (*garbage);
		(*garbage) = (*garbage)->next;
		free(temp->content);
		free(temp);
	}
	*garbage = NULL;
}
