/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:09:31 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/29 21:16:17 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	**return_head(void)
{
	static t_list	*head = NULL;

	return (&head);
}

t_list	**return_tail(void)
{
	static t_list	*tail = NULL;

	return (&tail);
}

void	addback(t_list *node)
{
	t_list	**tail;
	t_list	**head;

	tail = return_tail();
	head = return_head();
	if (*head == NULL)
	{
		*head = node;
		*tail = node;
	}
	else
	{
		(*tail)->next = node;
		*tail = node;
	}
}

void	*alloc(size_t size)
{
	void	*ptr;
	void	*node;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		perror("Fatal");
		garbage_collector();
	}
	node = ft_lstnew(ptr);
	if (node == NULL)
	{
		perror("Fatal");
		garbage_collector();
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
	exit(1);
}
