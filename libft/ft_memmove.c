/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:31:01 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/25 15:23:56 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (dest > src)
	{
		while (len-- > 0)
			((char *)dest)[len] = ((char *)src)[len];
	}
	else if (src > dest)
	{
		while (i < len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	t[] = "omarffdg hfg "; 
	char	s[] = "omarfhkkk ";
	printf("%s\n", ft_memmove(t, s + 1, 9));
	printf("%s\n", memmove(t, s + 1, 9));

	//x = memmove(t , s, 5);
	//printf("%s", x); 
}
*/
