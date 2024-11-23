/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:27:37 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/29 09:27:41 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_next;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		temp_next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp_next;
	}
}
/*
int main(void)
{
	t_list	*lst;
	int	*list[] = {
		malloc(sizeof(int)),
		malloc(sizeof(int)),
		malloc(sizeof(int)),
		malloc(sizeof(int)),
	};
	t_list	*head = NULL;
	for (int i = 0; i < 4; i++)
		*(list[i]) = i;
	head = ft_lstnew((void *)list[0]);
	head->next = ft_lstnew((void *)list[1]);
	head->next->next = ft_lstnew((void *)list[2]);
	head->next->next->next = ft_lstnew((void *)list[3]);
	ft_lstclear(&head, free);
	return (0);
}
*/
