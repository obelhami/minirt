/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:57:10 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/26 09:51:02 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	bytes;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	bytes = count * size;
	p = malloc(bytes);
	if (!p)
		return (NULL);
	ft_bzero(p, bytes);
	return (p);
}
