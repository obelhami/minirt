/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:01:44 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/24 15:01:15 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char testChar = '9'; // Change this character to test different cases

    if (ft_isalpha(testChar)) {
        printf("%c is an alphabetic character.\n", testChar);
    } else {
        printf("%c is not an alphabetic character.\n", testChar);
    }

    return 0;
}
*/
