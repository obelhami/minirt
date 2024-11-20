/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:47:58 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/24 15:31:42 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	c;
	int	b;

	c = 'A';
	b = '9';
	if (ft_isdigit(c))
		printf("the variable 'c' is digit \n");
	else
		printf("the variable 'c' is not digit \n");
    if (ft_isdigit(b))
        printf("the variable 'b' is digit \n");
    else
        printf("the variable 'b' is not digit \n");

}*/
