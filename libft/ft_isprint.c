/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:38:17 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/25 14:22:42 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int c;
    int b;

    c = 'A';
    b = '	';
    if (isprint(c))
        printf("the variable 'c' is digit \n");
    else
        printf("the variable 'c' is not digit \n");
    if (isprint(b))
        printf("the variable 'b' is digit \n");
    else
        printf("the variable 'b' is not digit \n");

}
*/
