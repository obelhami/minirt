/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:29:41 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/29 09:29:46 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
	t_list *one = NULL;
	t_list *two = NULL;
	t_list *three = NULL;
	t_list *four = NULL;

	one = (t_list *)malloc(sizeof(t_list));
	two = (t_list *)malloc(sizeof(t_list));
	three = (t_list *)malloc(sizeof(t_list));
	four = (t_list *)malloc(sizeof(t_list));

	one->content = "Hello";
	two->content = "Hello";
	three->content = "Hello";
	four->content = "Hello";

	one->next = two;
	two->next = three;
	three->next = four;
	four->next = NULL;

	printf("%d", ft_lstsize(one));
}
*/
