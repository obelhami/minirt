/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:14:02 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/19 20:15:32 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	in(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	return (str[i]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && in(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && in(set, s1[end]))
		end--;
	if (end == 0)
	{
		ptr = malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		return (&ptr[end]);
	}
	ptr = ft_substr(s1, start, (end - start) + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}
