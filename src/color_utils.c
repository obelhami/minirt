/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:55:38 by ajawad            #+#    #+#             */
/*   Updated: 2024/12/27 17:58:30 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_rgb	*color_multiplication(t_rgb *color1, t_rgb *color2)
{
	t_rgb	*resulted_color;

	resulted_color = malloc(sizeof(t_rgb));
	if (resulted_color == NULL)
		return (NULL);
	resulted_color->r = color1->r * color2->r;
	resulted_color->g = color1->g * color2->g;
	resulted_color->b = color1->b * color2->b;
	return (resulted_color);
}

inline t_rgb	*colors_addition(t_rgb *color1, t_rgb *color2)
{
	t_rgb	*resulted_color;

	if (color1 == NULL)
		return (color2);
	else if (color2 == NULL)
		return (color1);
	resulted_color = malloc(sizeof(t_rgb));
	if (resulted_color == NULL)
		return (NULL);
	resulted_color->r = color1->r + color2->r;
	resulted_color->g = color1->g + color2->g;
	resulted_color->b = color1->b + color2->b;
	return (resulted_color);
}

inline t_rgb	*scale_color(double scalar, t_rgb *color)
{
	t_rgb	*resulted_color;

	resulted_color = malloc(sizeof(t_rgb));
	if (resulted_color == NULL)
		return (NULL);
	resulted_color->r = scalar * color->r;
	resulted_color->g = scalar * color->g;
	resulted_color->b = scalar * color->b;
	return (resulted_color);
}
