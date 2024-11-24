/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:28:44 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/29 09:28:48 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*new = 0;
	t_list	*one = NULL;
	t_list	*two = NULL;
	t_list	*three = NULL;
	t_list	*four = 0;

	new = malloc(sizeof(t_list));
	one = malloc(sizeof(t_list));
	two = malloc(sizeof(t_list));
	three = malloc(sizeof(t_list));
	four = malloc(sizeof(t_list));

	new->content = "x";
	one->content = 0;
	two->content = "2";
	three->content = "3";
	four->content = "4";

	new->next = one;
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = 0;
	one = ft_lstlast(new);
	printf("%s", (char * )ft_lstlast(new)->content);
}
*/
