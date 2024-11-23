/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:12:35 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/09 15:42:07 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_put(char *str, long nb, int sign, int x)
{
	int	i;

	i = 0;
	if (str == 0)
		return (NULL);
	if (sign < 0)
	{
		str[i] = '-';
		i++;
	}
	while (x > 0)
	{
		str[i] = nb / x + '0';
		nb = nb % x;
		x = x / 10;
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	*allocation(int sign, int length)
{
	char	*str;

	if (sign < 0)
		str = malloc(sizeof(char) * (length + 2));
	else
		str = malloc(sizeof(char) * (length + 1));
	if (str == 0)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	int		sign;
	int		count;

	nb = n;
	sign = 1;
	if (nb < 0)
	{
		sign = -sign;
		nb = -nb;
	}
	i = 1;
	count = 1;
	while (nb / i >= 10)
	{
		i = i * 10;
		count++;
	}
	return (ft_put(allocation(sign, count), nb, sign, i));
}
