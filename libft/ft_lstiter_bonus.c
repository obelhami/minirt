/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:28:24 by obelhami          #+#    #+#             */
/*   Updated: 2023/12/01 08:22:25 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
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

	new->content = "a";
	one->content = "Hello";
	two->content = "c";
	three->content = "Z";
	four->content = "Bdkhdk";

	new->next = 0;
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = 0;
	//one = ft_lstlast(new);
	ft_lstiter(new, &f_upper);
	printf("%s", (char *)new->content);
}
*/
