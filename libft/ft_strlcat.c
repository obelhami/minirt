/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:04:18 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/25 15:32:07 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	size_of_src;
	size_t	size_of_dest;

	if (size == 0)
		return (ft_strlen(src));
	size_of_src = ft_strlen(src);
	size_of_dest = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && size_of_dest + i < (size - 1))
	{
		dest[i + size_of_dest] = src[i];
		i++;
	}
	dest[size_of_dest + i] = '\0';
	if (size_of_dest > size)
		return (size_of_src + size);
	return (size_of_dest + size_of_src);
}
/*
#include<stdio.h>
#include<string.h>

int main()
{
	printf("The original function : %zu\n" , strlcat(NULL, "klnsdkln" , 1));
	printf("our function : %zu\n" , ft_strlcat(NULL, "klnsdkln" , 1));
}
*/