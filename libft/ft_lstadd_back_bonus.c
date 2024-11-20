/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:25:59 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/29 09:26:05 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}
/*

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    t_list  *new = NULL;
    t_list  *one = NULL;
    t_list  *two = NULL;
    t_list  *three = NULL;
    t_list  *four = NULL;
	t_list *temp = NULL;

	temp = malloc(sizeof(t_list));
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
    two->next = four;
    three->next = NULL;
    four->next = NULL;
	temp = one;
    ft_lstadd_back(&one, new);

    while (temp)
    {
        printf("%s\n", temp->content);
        temp = temp->next;
	}
}
*/
