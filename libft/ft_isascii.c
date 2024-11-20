/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:29:21 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/25 14:20:56 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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

    c = 128;
    b = 0;
    if (isascii(c))
        printf("the variable 'c' is digit \n");
    else
        printf("the variable 'c' is not digit \n");
    if (isascii(b))
        printf("the variable 'b' is digit \n");
    else
        printf("the variable 'b' is not digit \n");

}
*/
