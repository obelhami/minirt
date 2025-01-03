/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 02:27:00 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/29 20:44:00 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static size_t	ftstrlen(const char *tab)
{
	size_t	i;

	i = 0;
	while (tab[i] && (tab[i] != ' ' && tab[i] != '\t'))
		i++;
	return (i);
}

static int	count_strings(char const *str)
{
	int	i;
	int	count;
	int	in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	**ft_ft_free(char **ptr, int j)
{
	while (j >= 0)
		free(ptr[j--]);
	free(ptr);
	return (NULL);
}

static char	**double_split(char **ptr, const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i])
		{
			ptr[j] = ft_substr(s, i, ftstrlen(s + i));
			if (ptr[j] == 0)
				return (ft_ft_free(ptr, j));
			j++;
		}
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
	}
	ptr[j] = 0;
	return (ptr);
}

char	**ft_ft_split(char const *s)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = (char **)alloc(sizeof(char *) * (count_strings(s) + 1));
	if (!ptr)
		return (NULL);
	return (double_split(ptr, s));
}
