/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:11:06 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/29 11:07:15 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	b;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		b = 0;
		while (haystack[i + b] == needle[b]
			&& i + b < len && haystack[i + b] && needle[b])
			b++;
		if (needle[b] == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
