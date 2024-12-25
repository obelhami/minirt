/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils_for_parsing.c                                :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: obelhami <obelhami@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/25 05:16:06 by obelhami		  #+#	#+#			 */
/*   Updated: 2024/12/25 06:42:18 by obelhami         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "minirt.h"

void	utils(char *str)
{
	printf("Error: the %s is invalid\n", str);
	exit(1);
}

void	ft_check_rgb(char **rgb, char *error)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (ft_ft_isdigit(rgb[i]) == 1)
		{
			printf("Error: the color of %s is invalid\n", error);
			exit(1);
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			printf("Error: the color of %s is invalid\n", error);
			exit(1);
		}
		i++;
	}
	if (i != 3)
		utils(error);
}

void	ft_check_isfloat(char **str, char *error)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isfloat(str[i]))
		{
			printf("Error: the %s is invalid\n", error);
			exit(1);
		}
		i++;
	}
	if (i != 3)
		utils(error);
}
