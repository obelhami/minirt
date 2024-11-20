/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:07:18 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/25 17:41:27 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
//	printf("%s\n", ft_strdup(NULL));
	printf("%s", strdup(NULL));
}
*/
