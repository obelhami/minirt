/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:03:21 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/25 15:57:48 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t number)
{
	size_t	i;

	i = 0;
	while (i < number)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world!";
    
    printf("Before bzero: %s\n", str);
    
    // Using bzero to zero out the string
    ft_bzero(NULL, sizeof(str));
    
    printf("After bzero: %s\n", str);

	bzero(str, sizeof(str));
    
    printf("After bzero: %s\n", str);
    
    return 0;
}
*/
