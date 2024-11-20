/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:40:41 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/24 20:02:39 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "omar";

	//printf("%s\n", ft_memset(s, 'a', 9));
    printf("%s", memset(s, 'a', 9));

}
*/
