/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:27:07 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/29 09:27:13 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*new = NULL;
	t_list	*one = NULL;
	t_list	*two = NULL;
	t_list	*three = NULL;
	t_list	*four = NULL;

	new = malloc(sizeof(t_list));
	one = malloc(sizeof(t_list));
	two = malloc(sizeof(t_list));
	three = malloc(sizeof(t_list));
	four = malloc(sizeof(t_list));

	new->content = "x";
	one->content = "1";
	two->content = "2";
	three->content = "3";
	four->content = "4";

	new->next = NULL;
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = NULL;
	ft_lstadd_front(&one, new);

	int	i = 0;
	while (new)
	{
		printf("%s", new->content);
		new = new->next;
	}
}
*/
