/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ajawad <marvin@42.fr>					  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/13 14:44:30 by ajawad			#+#	#+#			 */
/*   Updated: 2024/12/13 14:46:13 by ajawad           ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "minirt.h"

double	random_double(void)
{
	static unsigned long int	next = 12345;
	unsigned long int			a;
	unsigned long int			c;
	unsigned long int			m;

	a = 1664525;
	c = 1013904223;
	m = 4294967296;
	next = (a * next + c) % m;
	return ((double)next / (double)m);
}

inline double	interval_random_double(t_interval interval)
{
	return (interval.min + ((interval.max - interval.min) * random_double()));
}
