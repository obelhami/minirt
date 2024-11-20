/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:30:07 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/24 15:52:43 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s[] = "omar belhamid   ";
	
	printf("my function : %zu\n", ft_strlen(s));
    printf("original : %zu", strlen(s));
}
*/
