/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:58:41 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/25 14:20:24 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	a;
	int	b;

	a = ' ';
	b = '9';
	if (isalnum(a))
		printf("the variable 'a' is alnum\n");
	else
		printf("the variable 'a' is not alnum\n");
    if (isalnum(b))
        printf("the variable 'b' is alnum\n");
    else
        printf("the variable 'b' is not alnum\n");
}
*/
