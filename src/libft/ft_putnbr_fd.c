/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:12:51 by obelhami          #+#    #+#             */
/*   Updated: 2023/11/11 10:21:56 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		i;
	char	a;

	if (fd < 0)
		return ;
	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	i = 1;
	while (nb / i >= 10)
		i = i * 10;
	while (i > 0)
	{
		a = nb / i + '0';
		write(fd, &a, 1);
		nb = nb % i;
		i = i / 10;
	}
}
